#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tuple<int, int, int> t3;
typedef tree<t3 , null_type, less<t3> , rb_tree_tag ,
tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ordered_multiset s;
}