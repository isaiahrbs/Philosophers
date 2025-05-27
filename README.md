# 🍽️ Philosophers

A classic synchronization problem implementation in C, exploring the dining philosophers problem with threads and mutexes.

## 📖 About

The Dining Philosophers problem is a classic computer science problem used to illustrate synchronization issues and techniques for resolving them. In this problem, five philosophers sit around a circular table with five forks. Each philosopher alternates between thinking and eating. To eat, a philosopher needs both the fork to their left and the fork to their right.

## 🎯 The Challenge

- **No Deadlock**: Philosophers shouldn't get stuck waiting forever
- **No Starvation**: Every philosopher should eventually get to eat  
- **Concurrency**: Multiple philosophers can eat simultaneously
- **Resource Management**: Proper sharing of limited resources (forks)

## 🛠️ Compilation

### Prerequisites
- GCC compiler
- POSIX threads library
- Make utility

### Build Commands

```bash
# Compile the project
make

# Clean object files
make clean

# Full clean (remove executable)
make fclean

# Recompile everything
make re
```

## 🚀 Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

### Parameters

| Parameter | Description | Unit |
|-----------|-------------|------|
| `number_of_philosophers` | Number of philosophers (and forks) | count |
| `time_to_die` | Time before a philosopher dies without eating | milliseconds |
| `time_to_eat` | Time it takes for a philosopher to eat | milliseconds |
| `time_to_sleep` | Time a philosopher spends sleeping | milliseconds |
| `number_of_times_each_philosopher_must_eat` | Optional: stops when all philosophers eat this many times | count |

### Example Usage

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but stop after each philosopher eats 7 times
./philo 5 800 200 200 7

# Edge case: 1 philosopher (should die)
./philo 1 800 200 200

# Quick death scenario
./philo 4 310 200 100
```

## 📋 Program Output

The program outputs philosopher actions in real-time with emojis:

```
[timestamp]ms - P[philosopher_id]: has taken a fork. 🍴 [first fork]
[timestamp]ms - P[philosopher_id]: has taken a fork. 🍴 [second fork]
[timestamp]ms - P[philosopher_id]: is eating. 🍽️
[timestamp]ms - P[philosopher_id]: is sleeping. 😪🛏️
[timestamp]ms - P[philosopher_id]: is thinking. 💭
[timestamp]ms - P[philosopher_id]: died. ⚰️💀
```

### Example Output
```
4000ms - P3: has taken a fork. 🍴 [first fork]
4000ms - P4: is sleeping. 😪🛏️
4000ms - P3: has taken a fork. 🍴 [second fork]
4000ms - P3: is eating. 🍽️
4000ms - P1: has taken a fork. 🍴 [first fork]
4000ms - P1: has taken a fork. 🍴 [second fork]
4000ms - P1: is eating. 🍽️
4200ms - P4: is thinking. 💭
4200ms - P3: is sleeping. 😪🛏️
4200ms - P2: is thinking. 💭
4200ms - P2: has taken a fork. 🍴 [first fork]
4200ms - P1: is sleeping. 😪🛏️
4200ms - P2: has taken a fork. 🍴 [second fork]
4200ms - P2: is eating. 🍽️
```

## 🧠 Key Concepts

### 🍴 Forks
- Shared resources between adjacent philosophers
- Implemented as mutexes to prevent race conditions
- Each philosopher needs 2 forks to eat

### ⚰️ Death
- Occurs when a philosopher doesn't eat within `time_to_die` milliseconds
- Monitored by a separate death-checking thread
- Simulation ends immediately when any philosopher dies

### 😴 Sleep
- State after eating, before thinking
- Duration specified by `time_to_sleep` parameter
- Philosopher releases forks before sleeping

### 💭 Thinking  
- Default state when not eating or sleeping
- Philosopher waits for available forks
- No fixed duration (depends on fork availability)

### 🔄 Lifecycle
```
THINKING 💭 → (acquire forks 🍴🍴) → EATING 🍽️ → (release forks) → SLEEPING 😪🛏️ → THINKING 💭
```

## 🎨 Visual Representation

```
      🧔1
  🍴      🍴
🧔5   T    🧔2
🍴        🍴
  🧔4 🍴🧔3

T = Table
🧔 = Philosopher
🍴 = Fork
```

## ⚙️ Implementation Details

### Thread Management
- One thread per philosopher
- Main thread monitors for death/completion
- Proper thread creation and joining

### Mutex Usage
- One mutex per fork
- Print mutex to prevent output mixing
- Death mutex to protect death flag

### Race Condition Prevention
- Careful ordering of mutex locks
- Atomic operations where needed
- Proper cleanup on exit

## 🔒 Deadlock Solution

### My Approach: Fork Index Ordering

To prevent deadlock, I implemented a **fork ordering strategy** based on fork indices:

**How it works:**
- Each philosopher is assigned two forks (left and right)
- For example: Philosopher 2 gets forks 2 and 3
- **Key Rule**: Always acquire the fork with the **lowest index first**
- Philosopher 2 will wait for fork 2 to be free before attempting to take fork 3
- This creates a consistent ordering that prevents circular waiting

### Example Implementation
```c
// Determine which fork has lower index
if (philo->left_fork < philo->right_fork)
{
	first_fork = philo->left_fork;
	second_fork = philo->right_fork;
}
else
{
	first_fork = philo->right_fork;
	second_fork = philo->left_fork;
}

// Always take lower-indexed fork first
pthread_mutex_lock(&philo->simu->forks[first_fork].mutex);
safe_print(philo, "has taken a fork. 🍴 [first fork]");

pthread_mutex_lock(&philo->simu->forks[second_fork].mutex);
safe_print(philo, "has taken a fork. 🍴 [second fork]");

// Now philosopher can eat safely
```

### Why This Works
- **Prevents Circular Waiting**: No philosopher can create a cycle in the wait-for graph
- **Deterministic Order**: All philosophers follow the same fork acquisition rule
- **Deadlock-Free**: Impossible for all philosophers to be waiting in a circle
- **Simple & Efficient**: Easy to implement and understand

### Visual Example
```
Philosophers and their forks:
P1: forks 1,2 → takes 1 first, then 2
P2: forks 2,3 → takes 2 first, then 3  
P3: forks 3,4 → takes 3 first, then 4
P4: forks 4,5 → takes 4 first, then 5
P5: forks 5,1 → takes 1 first, then 5 ⭐
```

The key insight is philosopher 5: even though fork 5 is closer, they wait for fork 1 (lower index) first!

## 🐛 Common Issues & Solutions

### Data Races
- All shared data protected by mutexes
- Careful timing calculations
- Proper thread synchronization

## 📊 Testing Scenarios

### Basic Tests
- `./philo 5 800 200 200` - Should run indefinitely
- `./philo 1 800 200 200` - Single philosopher should die
- `./philo 5 800 200 200 7` - Should stop after 7 meals each

### Edge Cases
- `./philo 2 400 200 200` - Minimal viable case
- `./philo 5 200 100 100` - Quick death scenario
- `./philo 100 800 200 200` - Stress test with many philosophers

### Performance Tests
- Check for memory leaks with `valgrind`
- Verify no data races

## 🔍 Debugging Tips

### Valgrind
```bash
valgrind --tool=helgrind ./philo 5 800 200 200 4
valgrind --leak-check=full ./philo 5 800 200 200 5
```

## 🏆 Bonus Features

- Enhanced output formatting with colors
- Statistics tracking (meals eaten, time alive)
- Visualization mode
- Performance metrics

## 📚 Resources

- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [Mutex vs Semaphore](https://stackoverflow.com/questions/62814/difference-between-binary-semaphore-and-mutex)

## 📝 License

This project is part of the 42 School curriculum.

---
