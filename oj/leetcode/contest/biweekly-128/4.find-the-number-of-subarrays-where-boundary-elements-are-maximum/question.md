# [3113. 边界元素是最大值的子数组数目][link] (Hard)

[link]: https://leetcode.cn/contest/biweekly-contest-128/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/

给你一个 **正** 整数数组 `nums` 。

请你求出 `nums` 中有多少个子数组，满足子数组中 **第一个** 和 **最后一个** 元素都是这个子数组中的 **
最大** 值。

**示例 1：**

**输入：** nums = \[1,4,3,3,2\]

**输出：** 6

**解释：**

总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：

- 子数组 `[1,4,3,3,2]` ，最大元素为 1 ，第一个和最后一个元素都是 1 。
- 子数组 `[1,4,3,3,2]` ，最大元素为 4 ，第一个和最后一个元素都是 4 。
- 子数组 `[1,4,3,3,2]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[1,4,3,3,2]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[1,4,3,3,2]` ，最大元素为 2 ，第一个和最后一个元素都是 2 。
- 子数组 `[1,4,3,3,2]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。

所以我们返回 6 。

**示例 2：**

**输入：** nums = \[3,3,3\]

**输出：** 6

**解释：**

总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：

- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。
- 子数组 `[3,3,3]` ，最大元素为 3 ，第一个和最后一个元素都是 3 。

所以我们返回 6 。

**示例 3：**

**输入：** nums = \[1\]

**输出：** 1

**解释：**

`nums` 中只有一个子数组 `[1]` ，最大元素为 1 ，第一个和最后一个元素都是 1 。

所以我们返回 1 。

**提示：**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁹`