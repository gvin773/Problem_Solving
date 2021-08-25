#include <malloc.h>

struct pair
{
    int x, y;
};

struct queue
{
	queue* prev;
	queue* next;
	int __size;
	pair _data;

	queue* init(queue* head)
    {
		head = new queue();
		head->prev = head;
		head->next = head;
		head->__size = 0;
		head->_data = {-1, -1};
		return head;
	}

	void push(queue* head, pair data)
    {
		queue* tmp;
		tmp = new queue();
		tmp->_data = data;

		if (head->__size == 0)
        {
			tmp->prev = head;
			head->next = tmp;
		}
		else
        {
			queue* last = head->prev;
			tmp->prev = head->prev;
			last->next = tmp;
		}
		tmp->next = head;
		head->prev = tmp;
		head->__size += 1;
	}

	void pop(queue* head)
    {
		if (head->__size == 0) return;
		pair result = head->next->_data;
		queue* erase = head->next;
		head->next = head->next->next;
		head->next->prev = head;
		free(erase);
		head->__size -= 1;
		return;
	}

	int size(queue* head)
    {
		return head->__size;
	}

	bool empty(queue* head)
    {
		return (head->__size == 0);
	}

	pair front(queue* head)
    {
		pair result = head->next->_data;
		return result;
	}
};

int Map[10][10], len, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool visited[10][10];
queue* q;

void bfs_init(int N, int map[10][10])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) Map[i][j] = map[i][j];
    len = N;
}

int bfs(int y1, int x1, int y2, int x2)
{
    x1--, y1--, x2--, y2--;
    q = q->init(q);
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++) visited[i][j] = false;

    q->push(q, {x1, y1});
    visited[x1][y1] = true;

    int level = 0;
    while(!q->empty(q))
    {
        int Size = q->size(q);
        for(int i = 0; i < Size; i++)
        {
            int x = q->front(q).x, y = q->front(q).y;
            if(x == x2 && y == y2) return level;
            q->pop(q);
            for(int j = 0; j < 4; j++)
            {
                int nx = x+dx[j], ny = y+dy[j];
                if(0 <= nx && nx < len && 0 <= ny && ny < len && !visited[nx][ny] && Map[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q->push(q, {nx, ny});
                }
            }
        }
        level++;
    }

    return -1;
}
