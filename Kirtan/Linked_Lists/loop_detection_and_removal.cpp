//Author : Kyrtan
//Application of Doubly Linked List
#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200005;

class node{
public:
    int data;
    node* next;
    node* prev;
};

void insert_node(node** head, int val){
    if(*head == NULL){
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;
        *head = temp;
    }
    else{
        node* current = *head;
        while(current->next != NULL) current = current->next;
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        temp->prev = current;
        current->next = temp;
    }
}

void delete_node(node** head, int val){
    if((*head)->data == val){
        node* current = *head;
        current = current->next;
        *head = current;
        node* del_node = (*head)->prev;
        (*head)->prev = NULL;
        delete(del_node);
    }
    else{
        node* current = *head;
        node* nxt_node = current->next;
        while(nxt_node->data != val){
            current = current->next;
            nxt_node = nxt_node->next;
        }
        nxt_node = nxt_node->next;
        current->next = nxt_node;
        node* del_node = nxt_node->prev;
        nxt_node->prev = current;
        delete(del_node);
    }
}

void print(node** head){
    node* current = *head;
    cout<<current->data<<"---->";
    while(current->next != NULL){
        current = current->next;
        cout<<current->data<<"---->";
    }
    cout<<endl;
}

void remove_loop(node* loop_ptr, node** head){
    node* ptr1 = *head;
    node* ptr2 = loop_ptr;
    node* dummy = loop_ptr;
    int cnt = 0;
    while(ptr2->next != dummy){
        ptr2 = ptr2->next;
        cnt++;
    }
    ptr2 = *head;

    F0R(i,cnt) ptr2 = ptr2->next;

    while(ptr1 != ptr2->next){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr2->next = NULL;

    while(ptr2->prev != NULL) ptr2 = ptr2->prev;

    *head = ptr2;
}

bool detect_loop(node** head){

    node* slow_pnt = *head;
    node* fast_pnt = *head;
    while(fast_pnt != NULL){
        slow_pnt = slow_pnt->next;
        fast_pnt = fast_pnt->next;
        if(fast_pnt == NULL) break;
        fast_pnt = fast_pnt->next;
        if(fast_pnt == NULL) break;
        if(slow_pnt->data == fast_pnt->data){ remove_loop(slow_pnt,head); return true;}
    }
    return false;
}

int main(){
    struct node* dll = NULL;
    insert_node(&dll,3);
    insert_node(&dll,4);
    insert_node(&dll,5);
    insert_node(&dll,6);
    insert_node(&dll,7);
    insert_node(&dll,8);
    insert_node(&dll,9);
    insert_node(&dll,10);
    dll->next->next->next->next->next->next->next->next = dll->next->next->next;
    if(detect_loop(&dll)) cout<<"loop_detected and removed"<<endl;
    else cout<<"loop not detected"<<endl;
    print(&dll);
}

