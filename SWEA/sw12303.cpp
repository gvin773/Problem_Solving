#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
bool first = true;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    for(int i = 0; i < MAX_NODE; i++) node[i].next = nullptr;
    nodeCnt = 0;
    if(first)
    {
        head = new Node;
        first = false;
    }
    head->next = nullptr;
}

void addNode2Head(int data)
{
    auto temp = head->next;
    head->next = getNode(data);
    head->next->next = temp;
}

void addNode2Tail(int data)
{
    auto iter = head;
    for(; iter->next != nullptr; iter = iter->next) ;
    iter->next = getNode(data);
    iter->next->next = nullptr;
}

void addNode2Num(int data, int num)
{
    auto iter = head;
    for(int i = 1; i < num; i++) iter = iter->next;
    auto temp = iter->next;
    iter->next = getNode(data);
    iter->next->next = temp;
}

void removeNode(int data)
{
    auto iter = head;
    for(; iter->next != nullptr && iter->next->data != data; iter = iter->next) ;
    if(iter->next != nullptr) iter->next = iter->next->next;
}

int getList(int output[MAX_NODE])
{
    int cnt = 0;
    for(auto iter = head; iter->next != nullptr; iter = iter->next) output[cnt++] = iter->next->data;
    return cnt;
}
