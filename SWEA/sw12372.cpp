struct pair
{
    int x, y;
};

pair sorted[10];
int idx = 0;

void init()
{
    idx = 9;
}

void addUser(int uID, int height)
{
    if(idx >= 0)
    {
        bool check = false;
        int i = 9;
        for(i = idx+1; i < 10; i++) if(height > sorted[i].y || (height == sorted[i].y && uID < sorted[i].x)) break;
        if(i > 9)
        {
            check = true;
            for(int j = idx+1; j < 10; j++) sorted[j-1] = sorted[j];
            i = 10;
        }
        else if(i == idx+1)
        {
            check = true;
            i = idx+1;
        }
        for(int j = idx; j < i && !check; j++) sorted[j-1] = sorted[j];
        sorted[i-1] = {uID, height};
        idx--;
    }
    else
    {
        int i = 9;
        for(i = 0; i < 10; i++) if(height > sorted[i].y || (height == sorted[i].y && uID < sorted[i].x)) break;
        for(int j = 8; j >= i; j--) sorted[j+1] = sorted[j];
        if(i < 10) sorted[i] = {uID, height};
    }
}

int getTop10(int result[10])
{
    if(idx == -1) for(int i = 0; i < 10; i++) result[i] = sorted[i].x;
    else for(int i = 0; i < 10-idx; i++) result[i] = sorted[idx+1+i].x;
    return idx == -1 ? 10 : 9-idx;
}
