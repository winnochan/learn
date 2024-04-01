# python3
import heapq

from collections import namedtuple

AssignedJob = namedtuple("AssignedJob", ["started_at", "worker"])


def assign_jobs(n_workers, jobs):
    result = []
    free_workers = [AssignedJob(0, i) for i in range(n_workers)]
    heapq.heapify(free_workers)
    for job in jobs:
        worker = free_workers[0]
        new_work = AssignedJob(worker.started_at + job, worker.worker)
        heapq.heapreplace(free_workers, new_work)
        result.append(worker)

    return result


def main():
    # n_workers, n_jobs = map(int, input().split())
    # jobs = list(map(int, input().split()))
    # n_workers, n_jobs = 2, 5
    # jobs = list(map(int, '1 2 3 4 5'.split()))
    n_workers, n_jobs = 4, 20
    jobs = list(map(int, '1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1'.split()))
    assert len(jobs) == n_jobs

    assigned_jobs = assign_jobs(n_workers, jobs)

    for job in assigned_jobs:
        print(job.worker, job.started_at)


if __name__ == "__main__":
    main()
