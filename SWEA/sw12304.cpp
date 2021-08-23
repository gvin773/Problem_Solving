#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
bool first = true;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    for(int i = 0; i < MAX_NODE; i++)
    {
        node[i].prev = nullptr;
        node[i].next = nullptr;
    }
    nodeCnt = 0;
    if(first)
    {
        head = new Node;
        first = false;
    }
    head->prev = nullptr;
    head->next = nullptr;
}

void addNode2Head(int data)
{
    auto new_next = head->next;
    head->next = getNode(data);
    head->next->prev = head;
    head->next->next = new_next;
    if(new_next != nullptr) head->next->next->prev = head->next;
}

void addNode2Tail(int data)
{
    auto iter = head;
    for(; iter->next != nullptr; iter = iter->next) ;
    iter->next = getNode(data);
    iter->next->prev = iter;
    iter->next->next = nullptr;
}

void addNode2Num(int data, int num)
{
    auto iter = head;
    for(int i = 1; i < num; i++) iter = iter->next;
    auto new_next = iter->next;
    iter->next = getNode(data);
    iter->next->prev = iter;
    iter->next->next = new_next;
    if(new_next != nullptr) new_next->prev = iter->next;
}

int findNode(int data)
{
    int cnt = 1;
    for(auto iter = head; iter->next != nullptr && iter->next->data != data; iter = iter->next) cnt++;
    return cnt;
}

void removeNode(int data)
{
    auto iter = head;
    for(; iter->next != nullptr && iter->next->data != data; iter = iter->next) ;
    if(iter->next != nullptr)
    {
        iter->next = iter->next->next;
        if(iter->next != nullptr) iter->next->prev = iter;
    }
}

int getList(int output[MAX_NODE])
{
    int cnt = 0;
    for(auto iter = head; iter->next != nullptr; iter = iter->next) output[cnt++] = iter->next->data;
    return cnt;
}

int getReversedList(int output[MAX_NODE])
{
    int cnt = 0, ret;
    for(auto iter = head; iter->next != nullptr; iter = iter->next) cnt++; ret = cnt;
    for(auto iter = head; iter->next != nullptr; iter = iter->next) output[(cnt--)-1] = iter->next->data;
    return ret;
}
