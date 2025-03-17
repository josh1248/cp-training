void populate_partition(int total, int m, vi& curr, int s) {
//     if (s == total) {
//         partitions[total].emplace_back(curr);
//     } else if (s > total) {
//         return;
//     }

//     rep(i, m, total - s + 1) {
//         curr.emplace_back(i);
//         populate_partition(total, i + 1, curr, s + i);
//         curr.pop_back();
//     }
// }

// void populate_all_partitions() {
//     rep(i, 0, 1) {
//         // vi v;
//         // populate_partition(i, 1, v, 0);
//     }
// }