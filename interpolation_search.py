import numpy as np
import matplotlib.pyplot as plt
import timeit


def interpolationSearch(arr, target: int) -> tuple[int, int]:
    left = 0
    right = arr.size - 1
    steps = 0
    while arr[right] != arr[left] and arr[right] >= target >= arr[left]:
        steps += 1
        # оценка средняя
        mid = left + (target - arr[left]) * (right - left) // (arr[right] - arr[left])
        # Ключ найден
        if target == arr[mid]:
            return mid, steps
        # отбрасывает все элементы в правом пространстве поиска, включая средний элемент
        elif target < arr[mid]:
            right = mid - 1
        # отбрасывает все элементы в левой области поиска, включая средний элемент
        else:
            left = mid + 1
    if arr[right] == target:
        return right, steps
    # Цель не существует в списке
    return -1, steps


np.random.seed(30)
apriori = []
aposteriori = np.zeros((2, 6), dtype=float)
time = np.array([[0,0,0,0,0], [0,0,0,0,0]], dtype=float)
steps = np.zeros((2, 6), dtype=float)
k = 0
x = [1024, 4096, 16384, 65536, 262144, 524288]
for n in x:
    array_1 = 13 * np.arange(1, n + 1, dtype=np.uint32) - 3
    array_2 = np.sort(np.random.randint(1, n, n, dtype=np.uint32))
    apriori.append(np.log2(np.log2(n)))
    for targ in [0, n//4, n//2, 3*n//4, n-1]:
        res = 0
        res_step = 0
        cumulative = 0
        for j in range(10):
            start = timeit.default_timer()
            res,res_step = interpolationSearch(array_1, array_1[targ])
            finish = timeit.default_timer() - start
            cumulative += finish
        time[0, targ*4//n] = cumulative/10
        steps[0, k] += res_step
        if res != targ:
            print('error 1', n, res)
            break

        cumulative = 0
        for j in range(10):
            start = timeit.default_timer()
            res, res_step = interpolationSearch(array_2, array_2[targ])
            finish = timeit.default_timer() - start
            cumulative += finish
        time[1, targ*4//n] = cumulative / 10
        steps[1, k] += res_step
        if res == -1:
            print('error 2', n, res)
            break
    aposteriori[0][k] = np.mean(time[0])
    aposteriori[1][k] = np.mean(time[1])
    steps[0, k] /= 5
    steps[1, k] /= 5
    k += 1


print(aposteriori)
fig, ax = plt.subplots()
ax.plot(x, aposteriori[0]*1000, 'g', x, aposteriori[1]*1000, 'b')
ax.set_xlabel('number of elements')
ax.set_ylabel('time (ms)')
ax.grid(True)
ax.tick_params(axis='x', labelrotation=45)
plt.legend(['array_1', 'array_2'])
plt.show()
fig2, ax2 = plt.subplots()
fig2.suptitle('comparison of the number of a priori and a posteriori steps')
ax2.plot(x, apriori, 'r', x, steps[0], 'g', x, steps[1], 'b')
ax2.set_xlabel('number of elements')
ax2.set_ylabel('number of steps')
plt.legend(['priori', 'array_1', 'array_2'])
plt.show()
