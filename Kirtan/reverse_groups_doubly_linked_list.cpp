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

void reverse_ll(node** head){
    node* current = *head;
    node* next_node = NULL;
    node* prev_node = NULL;

    while(current != NULL){
        next_node = current->next;
        current->prev = next_node;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    *head = prev_node;
}

node* reverse_ll_recursive(node** head){
    node* current = *head;
    if(current->next == NULL){
        current->next = current->prev;
        current->prev = NULL;
        return current;
    }
    node* prev_node = reverse_ll_recursive(&(current->next));
    current->next = current->prev;
    current->prev = prev_node;
    if(current->next != NULL) return current;
    else{
        while(current->prev != NULL) current = current->prev;
        *head = current;
        return *head;
    }
}

void merge_ll(node** dll1,node** dll2){
    node* current = *dll1;
    while(current->next != NULL) current = current->next;
    current->next = *dll2;
    (*dll2)->prev = current;
}

void reverse_group_size(node** head, int group_size){
    int cnt = 0;
    node* current = *head;
    node* new_ll = NULL;
    node* temp;
    while(current != NULL){
        if(cnt % group_size == 0){
            temp = NULL;
            insert_node(&temp,current->data);
        }
        else if(cnt % group_size == group_size - 1){
            insert_node(&temp,current->data);
            reverse_ll_recursive(&temp);
            if(new_ll == NULL) new_ll = temp;
            else merge_ll(&new_ll,&temp);
        }
        else insert_node(&temp,current->data);

        current = current->next;
        cnt++;
    }

    reverse_ll_recursive(&temp);
    if(new_ll == NULL) new_ll = temp;
    else merge_ll(&new_ll,&temp);

    *head = new_ll;
}

int main(){
    struct node* dll = NULL;
    insert_node(&dll,22);
    insert_node(&dll,3);
    insert_node(&dll,99);
    insert_node(&dll,4);
    insert_node(&dll,5);
    insert_node(&dll,6);
    insert_node(&dll,7);
    insert_node(&dll,8);
    insert_node(&dll,9);
    insert_node(&dll,10);
    print(&dll);
    delete_node(&dll,99);
    print(&dll);
    delete_node(&dll,22);
    print(&dll);
    reverse_ll(&dll);
    print(&dll);
    reverse_ll_recursive(&dll);
    print(&dll);
    cout<<"Input group size:";
    int group_size;
    cin>>group_size;
    reverse_group_size(&dll,group_size);
    print(&dll);
}
