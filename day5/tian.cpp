#include <stdio.h>
// #include <conio.h>
// #include <math.h>
// #include <ctype.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
// #include <string.h>
// #include <sstream>
// #include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef pair<ll,ll> pl;
// #define INFint numeric_limits<int>::max()
// #define INFfloat numeric_limits<float>::infinity()
#define st first
#define nd second
const int MX = 2e9 + 7;
const int LM = INT_MAX;
const int TM = 1e6 + 2;
const int TT = 1e5 + 3;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ll UI = 1e15;
#define loop(n) for (int _ = 0; _ < n; _++)
#define loop1(n) for (int _ = 1; _ <= n; _++)
#define loopi(n) for (int i = 0; i < n; i++)
#define loopi1(n) for (int i = 1; i <= n; i++)
#define loopj(n) for (int j = 0; j < n; j++)
#define loopj1(n) for (int j = 1; j <= n; j++)
#define mbr(n,m) get<m>(n)
#define DEBUG 0
#define CASES 0
void getInt(char question[], int *answer, bool continuous = false) {
    // iostream in before out fix
	printf("%c%s ", (continuous ? '\0' : '\n'), question);
	scanf("%d", answer);
}
int randomVal() { return rand() % 99 + 1; }

typedef struct binary_node {
    int value, replica;
    binary_node *left, *right, *parent;
} bst;

int tmp_in, tmp_val; char responsePrefix[30];
bst *bstInit(int value) {
    bst *drill = new bst;
    drill -> value = value;
    drill -> left = NULL;
    drill -> right = NULL;
    drill -> parent = NULL;
    drill -> replica = 1;
    return drill;
}
bool bstOrder(bst *drill, bool initial = true) {
    if (initial) cout << "Order: ";
    if (drill == NULL) {
        if (initial) cout << "<Tree empty>" << endl;
        return false;
    } bstOrder(drill -> left, false);
    loop(drill -> replica) cout << drill -> value << " ";
    bstOrder(drill -> right, false);
    if (initial) cout << endl;
    return true;
}
bool bstPreOrder(bst *drill, bool initial = true) {
    if (initial) cout << "Pre-Order: ";
    if (drill == NULL) {
        if (initial) cout << "<Tree empty>" << endl;
        return false;
    } loop(drill -> replica) cout << drill -> value << " ";
    bstPreOrder(drill -> left, false);
    bstPreOrder(drill -> right, false);
    if (initial) cout << endl;
    return true;
}
bool bstPostOrder(bst *drill, bool initial = true) {
    if (initial) cout << "Post-Order: ";
    if (drill == NULL) {
        if (initial) cout << "<Tree empty>" << endl;
        return false;
    } bstPostOrder(drill -> left, false);
    bstPostOrder(drill -> right, false);
    loop(drill -> replica) cout << drill -> value << " ";
    if (initial) cout << endl;
    return true;
}
bst *bstBranch(bst *drill, int value) {
    if (drill == NULL) return bstInit(value);
    bst *leaf = new bst, *scout = drill, *buffer = drill;
    leaf -> value = value;
    leaf -> replica = 1;
    leaf -> left = NULL;
    leaf -> right = NULL;
    while (scout != NULL) {
        buffer = scout;
        if (leaf -> value == scout -> value) break;
        else if (leaf -> value < scout -> value) scout = scout -> left;
        else if (leaf -> value > scout -> value) scout = scout -> right;
    } leaf -> parent = buffer;
    if (leaf -> value == buffer -> value) { buffer -> replica += 1; delete leaf; }
    else if (leaf -> value < buffer -> value) buffer -> left = leaf;
    else if (leaf -> value >= buffer -> value) buffer -> right = leaf;
    return drill;
}
bool bstBreathFirst (bst *drill) {
    bst *buffer = drill; queue<bst *> holder;
    cout << "Breath first: ";
    if (buffer == NULL) {
        cout << "<Tree empty>" << endl;
        return false;
    } while (buffer != NULL) {
        loop(buffer -> replica) cout << buffer -> value << " ";
        if (buffer -> left != NULL) holder.push(buffer -> left);
        if (buffer -> right != NULL) holder.push(buffer -> right);
        if (!holder.empty()) {
            buffer = holder.front();
            holder.pop();
        } else buffer = NULL;
    } cout << endl; return true;
}
bool bstDepthFirst (bst *drill) {
    bst *buffer = drill; stack<bst *> holder;
    cout << "Depth first: ";
    if (buffer == NULL) {
        cout << "<Tree empty>" << endl;
        return false;
    } while (buffer != NULL) {
        loop(buffer -> replica) cout << buffer -> value << " ";
        if (buffer -> right != NULL) holder.push(buffer -> right);
        if (buffer -> left != NULL) holder.push(buffer -> left);
        if (holder.size()) {
            buffer = holder.top();
            holder.pop();
        } else buffer = NULL;
    } cout << endl; return true;
}
bst *bstSearch(bst* drill, int query) {
    if (drill == NULL) return NULL;
    if (query < drill -> value) return bstSearch(drill -> left, query);
    if (query > drill -> value) return bstSearch(drill -> right, query);
    if (query == drill -> value) return drill;
    else return NULL;
}
string bstFind(bst* drill, int query, bool initial = true) {
    if (initial) sprintf(responsePrefix, "Search result for key \"%d\": ", query);
    if (drill == NULL && initial) return (string)responsePrefix + "Tree empty\n";
    if (drill == NULL && !initial) return (string)responsePrefix + "Not exist\n";
    if (query < drill -> value) return bstFind(drill -> left, query, false);
    if (query > drill -> value) return bstFind(drill -> right, query, false);
    if (query == drill -> value) return (string)responsePrefix + "Exists\n";
}
bst *bstSmallest(bst *drill) {
    if (drill == NULL) return NULL;
    bst *buffer = drill;
    while (buffer -> left != NULL) buffer = buffer -> left;
    return buffer;
}
bst *bstLargest(bst *drill) {
    if (drill == NULL) return NULL;
    bst *buffer = drill;
    while (buffer -> right != NULL) buffer = buffer -> right;
    return buffer;
}
bool bstRemove(bst *drill, int value) {
    bst *buffer = bstSearch(drill, value);
    if (buffer == NULL) return false;
    if (buffer -> replica > 1) buffer -> replica -= 1;
    else {
        bst *holder = buffer -> parent, *tmp_node;
        if (buffer -> left == NULL && buffer -> right == NULL) {
            if (holder -> left == buffer) holder -> left = NULL;
            else holder -> right = NULL;
            delete buffer;
        } else if (buffer -> left != NULL xor buffer -> right != NULL) {
            if (buffer -> left != NULL) tmp_node = buffer -> left;
            else tmp_node = buffer -> right;
            if (holder -> left == buffer) holder -> left = tmp_node;
            else holder -> right = tmp_node;
            delete buffer;
        } else {
            bst *swap = buffer -> right;
            while (swap -> left != NULL) swap = swap -> left;
            // buffer -> value = swap -> value;
            // buffer -> replica = swap -> replica;
            if (swap -> right != NULL) swap -> right -> parent = holder;
            if (holder -> left == swap) holder -> left = swap -> right;
            else holder -> right = swap -> right;
            delete buffer; buffer = swap;
        }
    } return true;
}
bst *bstNearestSmaller(bst *branch) {
    if (branch -> left == NULL && branch -> right == NULL) return NULL;
    unsigned int range = INT_MAX, tmp_answer;
    bst *buffer = branch, *holder = NULL; stack<bst *> lookup;
    while (buffer != NULL && range > 1) {
        if (buffer -> right != NULL) lookup.push(buffer -> right);
        if (buffer -> left != NULL) lookup.push(buffer -> left);
        if (!lookup.empty()) {
            buffer = lookup.top();
            lookup.pop();
        } else { buffer = NULL; break; }
        tmp_answer = branch -> value - buffer -> value;
        if (tmp_answer < range && tmp_answer > 0) {
            range = tmp_answer;
            holder = buffer;
        }
    } return holder;
}
bst *bstNearestLarger(bst *branch) {
    if (branch -> left == NULL && branch -> right == NULL) return NULL;
    unsigned int range = INT_MAX, tmp_answer;
    bst *buffer = branch, *holder = NULL; stack<bst *> lookup;
    while (buffer != NULL && range > 1) {
        if (buffer -> left != NULL) lookup.push(buffer -> left);
        if (buffer -> right != NULL) lookup.push(buffer -> right);
        if (!lookup.empty()) {
            buffer = lookup.top();
            lookup.pop();
        } else { buffer = NULL; break; }
        tmp_answer = buffer -> value - branch -> value;
        if (tmp_answer < range && tmp_answer > 0) {
            range = tmp_answer;
            holder = buffer;
        }
    } return holder;
}

void real_process() {
    // Creating
    getInt("Initiating tree with value:", &tmp_in);
    bst *tree = bstInit(tmp_in);
    bstOrder(tree);

    // Insertion
    getInt("Amount of child node to add:", &tmp_val);
    loop(tmp_val) {
        getInt("Add child node of value:", &tmp_in, true);
        bstBranch(tree, tmp_in);
    } cout << endl; bstOrder(tree);

    // Traversions
    bstBreathFirst(tree);
    bstDepthFirst(tree);

    // Searches
    getInt("Search for:", &tmp_in);
    cout << bstFind(tree, tmp_in) << endl;
    // bst* result_node = bstSearch(tree, tmp_in);

    cout << "Largest item: " << bstLargest(tree) -> value << endl;
    cout << "Smallest item: " << bstSmallest(tree) -> value << endl;

    // cout << "[Debugger]~$ Near sm(5): " << bstNearestSmaller(bstSearch(tree, 5)) -> value << endl;
    // cout << "[Debugger]~$ Near lg(5): " << bstNearestLarger(bstSearch(tree, 5)) -> value << endl;

    // Deletion
    getInt("Amount of child node to delete:", &tmp_val);
    loop(tmp_val) {
        getInt("Delete child node of value:", &tmp_in, true);
        bstRemove(tree, tmp_in);
    } cout << endl; bstOrder(tree);

    /***
     * 5
     * 4
     * 2
     * 7
     * 1
     * 9
     * 3
     * 2
     * 8
     * 1
     * 
     ***/

    return;
}

int main() {
    #ifndef DEBUG
    freopen("test_case.in", "r", stdin);
    freopen("test_case.out", "w", stdout);
    #endif
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int t(1);
    if (CASES) cin >> t;
    while(t--) real_process();
    return 0;
}
