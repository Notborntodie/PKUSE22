#include <iostream>
using namespace std;
#define MAX 20
class graph {
public:
    int num;    //图中点的数量
    string Dot[MAX];        //点的名称
    bool tag[MAX];      //访问过与否
    int side[MAX][MAX];
    int Dout[MAX], Din[MAX];
    string ans[MAX];
    graph() {
        cout << "input number of points" << endl;
        cin >> num;
        memset(side, 0, sizeof(side));      //所有初始化条件均设置为0
        memset(Dout, 0, sizeof(Dout));
        memset(Din, 0, sizeof(Din));
        memset(tag, 0, sizeof(tag));
        for (int i = 0; i < num; i++) {
            cout << "name of dot" << i << ":";
            cin >> Dot[i];
            ans[i] = Dot[i];
        }
        cout << "input edge:" << endl;
        while (1) {
            string s;
            cin >> s;
            if (s == "0")
                break;
            else {
                int from = (int)s[1] - 48;
                int to = (int)s[3] - 48;
                side[from][to] = 1;
                Dout[from] = 1;
                Din[to] = 1;
            }
        }
    }
    bool Order(int i, int pos) {            //判断是否满足拓扑排序的要求
        for (int j = 0; j < pos; j++) {
            for (int k = 0; k < num; k++) {
                if (ans[j] == Dot[k])
                    if (side[i][k])
                        return 0;
            }
        }
        return 1;
    }
    void setTag() {
        memset(tag, 0, sizeof(tag));
    }
    void TopoSort(int pos) {
        if (pos == num) {
            for (int i = 0; i < num; i++)
                cout << ans[i] << " ";
            cout << endl;
        }

                
        else {
            for (int i = 0; i < num; i++) {
                if (tag[i] == 0 && Order(i, pos)) {
                    tag[i] = 1;
                    ans[pos] = Dot[i];
                    TopoSort(pos + 1);
                    tag[i] = 0;
                }
            }
        }
    }
    void Topo_All() {
        setTag();
        TopoSort(0);
    }
};

int main()
{
    graph a;
    a.Topo_All();
    return 0;
}

