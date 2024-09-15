#pragma once
#include <atomic>
#include <cstddef>
#include <thread>

namespace slib {

class jthread {
private:
  std::atomic<bool> runFlag{true};
  std::thread activeThread;

public:
  template <typename Fn, typename... Args>
  jthread(Fn &&fn, Args &&...args)
      : activeThread{std::forward<Fn>(fn), std::ref(runFlag),
                     std::forward<Args>(args)...} {}

  jthread(const jthread &) = delete;
  jthread(jthread &&other) noexcept
      : runFlag(other.runFlag.load()),
        activeThread(std::move(other.activeThread)) {
    other.runFlag = false; // Ensure the moved-from object is stopped
  }

  jthread &operator=(const jthread &) = delete;
  jthread &operator=(jthread &&other) noexcept {
    if (this != &other) {
      if (activeThread.joinable()) {
        runFlag = false;
        activeThread.join();
      }

      runFlag = other.runFlag.load();
      activeThread = std::move(other.activeThread);

      other.runFlag = false;
    }
    return *this;
  }
  ~jthread() {
    runFlag = false;
    if (activeThread.joinable())
      activeThread.join();
  }
};

} // namespace slib
