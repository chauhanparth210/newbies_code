//Author : Kyrtan
//Implementation of Singly Linked List
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
};

void insert_node(node** head, int val){
    if(*head == NULL){
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        *head = temp;
    }
    else{
        node* current = *head;
        while(current->next != NULL) current = current->next;
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        current->next = temp;
    }
}

void delete_node(node** head, int val){
    if((*head)->data == val){
        node* current = *head;
        node* del_node = *head;
        current = current->next;
        *head = current;
        delete(del_node);
    }
    else{
        node* current = *head;
        node* nxt_node = current->next;
        while(nxt_node->data != val){
            current = current->next;
            nxt_node = nxt_node->next;
        }
        node* del_node = nxt_node;
        nxt_node = nxt_node->next;
        current->next = nxt_node;
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

void merge(node** head1, node** head2){
    node* current = *head1;
    while(current->next != NULL) current = current->next;
    current->next = *head2;
}

int main(){
    struct node* sll1 = NULL;
    insert_node(&sll1,22);
    insert_node(&sll1,3);
    insert_node(&sll1,99);
    insert_node(&sll1,4);
    insert_node(&sll1,5);
    insert_node(&sll1,6);
    insert_node(&sll1,7);
    print(&sll1);
    delete_node(&sll1,99);
    print(&sll1);
    delete_node(&sll1,22);
    print(&sll1);
    struct node* sll2 = NULL;
    insert_node(&sll2,8);
    insert_node(&sll2,9);
    insert_node(&sll2,10);
    print(&sll2);
    merge(&sll1,&sll2);
    print(&sll1);
}
