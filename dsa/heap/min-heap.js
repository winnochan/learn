class Node {
  constructor(idx, val) {
    this.idx = idx;
    this.val = val;
  }
}

function defaultCmp(a, b) {
  if (a === b) return 0;
  if (a < b) return -1;
  return 1;
}

class Heap {
  constructor(cap, arr, cmp) {
    this.cmp = cmp || defaultCmp; // 比较器
    this.cap = cap; // 容量
    this.idx = 0; // 自增ID
    this.heap = new Array(cap);
    this.map = new WeakMap();

    if (arr) {
      this.size = arr.length;
      for (let i = 0; i < this.size; i++) {
        this.heap[i] = arr[i];
      }
      this.heapify();
    } else {
      this.size = 0;
    }
  }

  static from(cap, arr, cmp) {
    return new Heap(cap, arr, cmp);
  }

  isEmpty() {
    return this.size <= 0;
  }

  isFull() {
    return this.cap > 0 && this.size >= this.cap;
  }

  peek() {
    if (this.size <= 0) return;
    return this.heap[0];
  }

  pop() {
    if (this.size <= 0) {
      return;
    }
    if (this.size === 1) {
      return this.heap[--this.size];
    }
    this.swap(0, --this.size);
    this.siftDown(0);
    return this.heap[this.size];
  }

  push(val) {
    if (this.isFull()) return;
    this.heap[this.size] = val;
    this.swimUp(this.size++);
  }

  pushpop(val) {
    if (this.isEmpty()) {
      return this.push(val);
    }
    let ret = this.heap[0];
    this.heap[0] = val;
    this.siftDown(0);
    return ret;
  }

  pushpopWhenFull(val) {
    if (this.isFull()) {
      return this.pushpop(val);
    } else {
      return this.push(val);
    }
  }

  heapify() {
    for (let i = this.parent(this.size - 1); i >= 0; i--) {
      this.siftDown(i);
    }
  }

  siftDown(i) {
    let l;
    let r;
    let c;
    while (i < this.size) {
      c = i;
      l = this.left(i);
      r = this.right(i);
      if (l < this.size && this.cmp(this.heap[l], this.heap[c]) < 0) {
        c = l;
      }
      if (r < this.size && this.cmp(this.heap[r], this.heap[c]) < 0) {
        c = r;
      }
      if (i === c) break;

      this.swap(c, i);
      i = c;
    }
  }

  swimUp(i) {
    let p;
    while (i > 0) {
      p = this.parent(i);
      if (this.cmp(this.heap[p], this.heap[i]) <= 0) {
        break;
      }
      this.swap(p, i);
      i = p;
    }
  }

  parent(i) {
    return (i - 1) >> 1;
  }

  left(i) {
    return (i << 1) + 1;
  }

  right(i) {
    return (i << 1) + 2;
  }

  swap(j, k) {
    if (j !== k) {
      let temp = this.heap[j];
      this.heap[j] = this.heap[k];
      this.heap[k] = temp;
    }
  }
}

if (require.main === module) {
  const TN = 1000;
  const N = 10000;
  for (let i = 0; i < TN; i++) {
    let arr = new Array(N).fill(0).map(() => Math.floor(N * Math.random()));

    let heap = Heap.from(N, arr);
    arr.sort((a, b) => a - b);
    for (let j = 0; j < arr.length; j++) {
      let n = arr[j];
      let p = heap.pop();
      if (n !== p) {
        // console.log(`[error]`, arr);
        console.log(j, n, p, arr);
        break;
      }
    }
  }
}
