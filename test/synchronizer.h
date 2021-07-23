#pragma once

#include <condition_variable>
#include <cstdint>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

// sender invokes start_transaction and start an async call
// receiver call end_transaction after receive response
// test case will call wait() to wait until transaction finishes
class Synchronizer {
private:
  std::mutex m_;
  std::condition_variable cv_;
  bool ready_{true};

public:
  int32_t start_transaction(std::function<int32_t(void)> f) {
    {
      // start transaction only when it's ready
      std::unique_lock<std::mutex> lock{m_};
      cv_.wait(lock, [this] { return ready_; });
      ready_ = false;
      // std::cout << "start transaction in " << std::this_thread::get_id()
      //           << " thread\n";
    }
    auto result = f();
    return result;
  }

  void end_transaction() {
    {
      std::lock_guard<std::mutex> lg(m_);
      ready_ = true;
      // std::cout << "end transaction in " << std::this_thread::get_id()
      //           << " thread\n";
    }
    cv_.notify_one();
  }

  void wait() {
    std::unique_lock<std::mutex> lock{m_};
    cv_.wait(lock, [this] { return ready_; });
  }
};
