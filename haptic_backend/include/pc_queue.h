/**
 * @file pc_queue.h
 * @author Ishita Gupta (ishita.gupta@addverb.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PC_QUEUE_H_
#define PC_QUEUE_H_

#include <atomic>
#include <optional>
#include <vector>

template<typename T>
class pc_queue {
public:
  /**
   * @brief Construct a new pc queue object
   * 
   * @param capacity 
   */
  explicit pc_queue(size_t capacity);
  
  /**
   * @brief Destroy the pc queue object
   * 
   */
  ~pc_queue();

  /**
   * @brief Enqueuee value if there is capacity
   * 
   * @param v 
   * @return true 
   * @return false 
   */
  bool enqueue(const T& v);

  /**
   * @brief 
   * 
   * @return std::optional<T> 
   */
  std::optional<T> dequeue();

  /**
   * @brief return if queue size is 0
   * 
   * @return true 
   * @return false 
   */
  bool isEmpty() const {
    return size_.load(std::memory_order_acquire) == 0;
  }

  std::mutex back_mutex;

private:
  /// @brief max elements queue can hold
  const size_t capacity_;
  /// @brief 
  std::vector<T> data_;
  /// @brief queue's front index
  size_t front_ = 0;
  /// @brief queue's back index
  size_t back_ = 0;
  /// @brief current size of queue
  std::atomic<size_t> size_ = 0;
};

template<typename T>
pc_queue<T>::pc_queue(size_t capacity) : capacity_(capacity), data_(capacity) {}

template<typename T>
pc_queue<T>::~pc_queue() {}

template<typename T>
bool pc_queue<T>::enqueue(const T& v) {
  // 
  if (size_.load(std::memory_order_relaxed) >= capacity_)
    return false;
  // increment the back index, circular way
  data_[(back_ % capacity_)] = v;
  back_mutex.lock();
  back_++;
  back_mutex.unlock();
  size_.fetch_add(1, std::memory_order_release);
  return true;
}

template<typename T>
std::optional<T> pc_queue<T>::dequeue() {
  if (size_.load(std::memory_order_acquire) == 0)
    return std::optional<T>(std::nullopt);
  std::optional<T> res = std::move(data_[(front_++ % capacity_)]);
  size_.fetch_sub(1, std::memory_order_relaxed);
  return res;
}

#endif
