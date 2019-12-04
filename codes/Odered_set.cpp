#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds; // or pb_ds;
template<typename T, typename B = null_type>
using oset = tree<T, B, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    oset< int > ost;
    ost.insert(1);
    ost.insert(2);
    ost.insert(4);
    ost.insert(8);
    ost.insert(16);

    // returns an iterator to the k-th largest element (counting from zero)
    cout<<*ost.find_by_order(1)<<endl; // 2
    cout<<*ost.find_by_order(2)<<endl; // 4
    cout<<*ost.find_by_order(4)<<endl; // 16
    cout<<(end(ost)==ost.find_by_order(6))<<endl; // true

    // number of items in a set that are strictly smaller than our item
    cout<<ost.order_of_key(-5)<<endl;  // 0
    cout<<ost.order_of_key(1)<<endl;   // 0
    cout<<ost.order_of_key(3)<<endl;   // 2
    cout<<ost.order_of_key(4)<<endl;   // 2
    cout<<ost.order_of_key(400)<<endl; // 5
}