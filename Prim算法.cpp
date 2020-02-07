#include<iostream>
#include<queue>

using namespace std;

#define MAXVEX 20
#define INFINITY 7777	//���ڳ�ʼ��ʱ����ڽӾ��� 

typedef struct Graph {
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}*pGraph; 

void CreateGraph(Graph &graph) {
	cout << "���붥�����ͱ���:";
	cin >>  graph.numVertexes >> graph.numEdges;
	
	//��������� 
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << "�������" << i + 1 << "��������:"; 
		cin >> graph.vexs[i];
	}
	
	//��ʼ���ڽӾ���
	for(int i = 0; i < graph.numVertexes; ++i) {
		for(int j = 0; j < graph.numVertexes; ++j) {
			graph.arc[i][j] = INFINITY;
		}
	} 
	
	//�����ڽӾ���
	int x, y, w;
	for(int i = 0; i < graph.numEdges; ++i) {
		cout << "����ߵ��±�x,y��Ȩֵw:";
		cin >> x >> y >> w;
		graph.arc[x][y] = w;
		graph.arc[y][x] = w;
	}
}

void MiniSpanTreeByPrim(Graph &graph) {
	int adjVex[MAXVEX];	//������ض����±� 
	int lowCost[MAXVEX];//������ض����ߵ�Ȩֵ 
	lowCost[0] = 0;		//��ʼ����һ��ȨֵΪ0��������0������������
						//��һ�������Ӧ������Ϊ0����ʾ�ö����Ѽ��������� 
	adjVex[0] = 0;		//��ʼ����һ��������±�Ϊ0��
	//ѭ������0������֮������ж��� 
	for(int i = 0; i <graph.numVertexes; ++i) {
		lowCost[i] = graph.arc[0][i];	//��0�Ŷ����Ӧ���ڽӾ����е���һ�п�������lowCost 
		adjVex[i] = 0;			//�����ж����Ӧ���±궼��ʼ��Ϊ0�Ŷ�����±ꣻ 
	}
	
	int min, j, k;
	for(int i = 1; i < graph.numVertexes; ++i) {
		min = INFINITY;
		j = 1;
		k = 0;
		while(j < graph.numVertexes) {
			//�ж�j�Ŷ���δ��������������j��0�Ŷ���ıߵ�Ȩֵ��С��Ȼ��j����Ÿ�k 
			if(lowCost[j] != 0 && lowCost[j] < min) {
				min = lowCost[j];
				k = j;
			}
			++j;
		}
		//��ӡ��ǰ������е���СȨֵ��adjVex���Ѿ���������µ����飬
		//ֻҪ����ö���������Ķ��㣬����ض������ڽӱ��е�λ�þͻᱻ���³Ƹö��� 
		//���ѽ������������������ڽӱ������δ����ÿһ�������г���Ӧ��adjVex�����lowCost���� 
		cout << adjVex[k] << "--" << k << "\t";
		lowCost[k] = 0;//���Ϊk�Ķ����Ѿ���������������������������lowCost�е�λ�ñ���Ϊ0 
		
		//���ѭ�������������k����ض����Ӧ��lowCost���� 
		for(int i = 1; i < graph.numVertexes; ++i) {
			if(lowCost[i] != 0 && graph.arc[k][i] < lowCost[i]) {
				lowCost[i] = graph.arc[k][i];
				adjVex[i] = k;//����k������صĶ������Ŷ���Ϊk����ռ�б�־������һ��ѭ����ʹ�� 
			}
		}
	}
	
} 

int main() {
	Graph graph;
	CreateGraph(graph);
	
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << "\t" << graph.vexs[i];
	}
	cout << "\n\n";
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << graph.vexs[i] << "\t";
		for(int j = 0; j < graph.numVertexes; ++j) {
			cout << graph.arc[i][j] << "\t";
		}
		cout << "\n\n";
	}
	
	MiniSpanTreeByPrim(graph);
	
	getchar();
	return 0;
}
