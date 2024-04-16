# [3115. 素数的最大距离][link] (Medium)

[link]: https://leetcode.cn/contest/weekly-contest-393/problems/maximum-prime-difference/

给你一个整数数组 `nums`。

返回两个（不一定不同的）素数在 `nums` 中 **下标** 的 **最大距离**。

**示例 1：**

**输入：** nums = \[4,2,9,5,3\]

**输出：** 3

**解释：** `nums[1]`、 `nums[3]` 和 `nums[4]` 是素数。因此答案是 `|4 - 1| = 3`。

**示例 2：**

**输入：** nums = \[4,8,2,8\]

**输出：** 0

**解释：** `nums[2]` 是素数。因为只有一个素数，所以答案是 `|2 - 2| = 0`。

**提示：**

- `1 <= nums.length <= 3 * 10⁵`
- `1 <= nums[i] <= 100`
- 输入保证 `nums` 中至少有一个素数。
