int child[100][100] = {}, cnt[100] = {}, ans;

void dfs_init(int N, int path[100][2])
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++) child[i][j] = 0;
        cnt[i] = 0;
    }

    for(int i = 0; i < N; i++)
        child[path[i][0]][cnt[path[i][0]]++] = path[i][1];
}

void get_ans(int now, int n)
{
    if(ans != -1) return;
    if(cnt[now] == 0)
    {
        ans = -1;
        return;
    }
    for(int i = 0; i < cnt[now]; i++)
    {
        if(child[now][i] > n && ans == -1)
        {
            ans = child[now][i];
            return;
        }
        else if(ans == -1) get_ans(child[now][i], n);
    }
}

int dfs(int n)
{
    ans = -1;
    get_ans(n, n);
    return ans;
}

