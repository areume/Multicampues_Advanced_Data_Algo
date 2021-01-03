#pragma warning(disable: 4996)

/***********************************************************/
// �� ����
/***********************************************************/
#if 0

#include <stdio.h>

int N;
int a[30000 + 10];

void Qsort(int start, int end)
{
	int pivot, left, target, temp;

	if (start >= end) return;
	pivot = end;
	target = start;
	for (left = start; left < end; left++)
	{
		if (a[left] < a[pivot])
		{
			temp = a[left];
			a[left] = a[target];
			a[target] = temp;
			target++;
		}
	}
	temp = a[pivot];
	a[pivot] = a[target];
	a[target] = temp;

	Qsort(start, target - 1);
	Qsort(target + 1, end);
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	Qsort(0, N - 1);
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

#endif

/***********************************************************/
// Merge ����
/***********************************************************/
#if 0

#include <stdio.h>

int N;
int a[30000 + 10];
int buf[30000 + 10];

void Msort(int start, int end)
{
	int mid, i, j, k;

	if (start >= end) return;

	mid = (start + end) / 2;
	Msort(start, mid);
	Msort(mid + 1, end);

	i = start; j = mid + 1; k = start;

	while (i <= mid && j <= end) {
		if (a[i] < a[j]) buf[k++] = a[i++];
		else buf[k++] = a[j++];
	}
	while (i <= mid) {
		buf[k++] = a[i++];
	}
	while (j <= end) {
		buf[k++] = a[j++];
	}
	for (i = start; i <= end; i++) a[i] = buf[i];
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	Msort(0, N - 1);
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

#endif

/***********************************************************/
// ���� Ž��
/***********************************************************/
#if 0

#include <stdio.h>

int a[50000 + 10];
int N;

int Bin_Search(int start, int end, int data)
{
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] == data) return mid + 1;
		else if (a[mid] < data) start = mid + 1;
		else if (a[mid] > data) end = mid - 1;
	}
	return 0;
}

int main(void)
{
	int i, T, data;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &data);
		printf("%d\n", Bin_Search(0, N - 1, data));
	}
}

#endif

/***********************************************************/
// ���� ī����
/***********************************************************/
#if 0

#include <stdio.h>

int N, M;
int a[30000 + 10];

int Bin_Search_Lower(int start, int end, int data)
{
	int sol = -1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] == data)
		{
			sol = mid;
			end = mid - 1;
		}
		else if (a[mid] < data) start = mid + 1;
		else end = mid - 1;
	}
	return sol;
}

int Bin_Search_Upper(int start, int end, int data)
{
	int sol = -1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] == data)
		{
			sol = mid;
			start = mid + 1;
		}
		else if (a[mid] < data) start = mid + 1;
		else end = mid - 1;
	}
	return sol;
}

int main(void)
{
	int i, data, lower, upper;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &data);
		lower = Bin_Search_Lower(0, N - 1, data);
		if (lower != -1)
		{
			upper = Bin_Search_Upper(0, N - 1, data);
			printf("%d ", upper - lower + 1);
		}
		else printf("0 ");
	}
	printf("\n");
	return 0;
}

#endif

/***********************************************************/
// ���� ī���� (����)
/***********************************************************/
#if 0

#include <stdio.h>

int N;
int a[30000 + 10];

int Bin_Search_Lower(int start, int end, int data)
{
	int sol = -1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] >= data)
		{
			sol = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	return sol;
}

int Bin_Search_Upper(int start, int end, int data)
{
	int sol = -1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] <= data)
		{
			sol = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	return sol;
}

int main(void)
{
	int i, data, lower, upper;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);

	lower = Bin_Search_Lower(0, N - 1, 5);
	if (lower != -1)
	{
		upper = Bin_Search_Upper(0, N - 1, 15);
		printf("%d\n", upper - lower + 1);
	}
	return 0;
}

#endif

/***********************************************************/
// ����
/***********************************************************/
#if 0

#include <stdio.h>

int N, cnt;
int arr[1000 + 10];

void Qsort(int start, int end)
{
	int pivot, left, target, temp;

	if (start >= end) return;
	pivot = end;
	target = start;
	for (left = start; left < end; left++)
	{
		if (arr[left] < arr[pivot])
		{
			temp = arr[left];
			arr[left] = arr[target];
			arr[target] = temp;
			target++;
		}
	}
	temp = arr[pivot];
	arr[pivot] = arr[target];
	arr[target] = temp;

	Qsort(start, target - 1);
	Qsort(target + 1, end);
}

int Binary_Search_Lower(int start, int end, int data)
{
	int sol = -1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] >= data)
		{
			sol = mid;
			end = mid - 1;
			// �� ���� ���� ã�� ���� ���� Ž��.
		}
		else start = mid + 1;
	}
	return sol;
}

int Binary_Search_Upper(int start, int end, int data)
{
	int sol = -1, mid;

	if (data > arr[N - 1]) end = N - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] <= data)
		{
			sol = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	return sol;
}

int main(void)
{
	int i, j, k, dist, start, end, lower, upper;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &arr[i]);
	Qsort(0, N - 1);

	// 3�� for �� �̿�
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			for (k = j + 1; k < N; k++) {
				// if (arr[k] - a[j] < arr[j] - arr[i] ) continue;
				// else if ( arr[k] - a[j] > (arr[j] - arr[i]) * 2) break;
				if (arr[j] - arr[i] <= arr[k] - arr[j] && \
					(arr[j] - arr[i]) * 2 >= arr[k] - arr[j]) cnt++;
			}
		}
	}
	printf("%d\n", cnt);

	// ����Ž�� �̿�
	cnt = 0;
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {

			dist = arr[j] - arr[i];
			// start ~ end ���� �̳��� �糡 ��� ��ġ�� �̿�
			start = arr[j] + dist;
			end = arr[j] + dist * 2;
			// start �̻� �߿��� ���� ���� ���� ��ġ Ž��.
			lower = Binary_Search_Lower(0, N - 1, start);
			// ��ã�� ��쳪 ������ ����� �ּҰ��� ã�� ��� ��ŵ.
			if (lower == -1 || arr[lower] > end) continue;

			upper = Binary_Search_Upper(0, N - 1, end);
			cnt += upper - lower + 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

#endif

/***********************************************************/
// ����
/***********************************************************/
#if 0

#include <stdio.h>

int N, M;
int budget[10010];

int Check(int mid)
{
	int i, sum = 0;
	for (i = 1; i <= N; i++) {
		if (budget[i] >= mid) sum += mid;
		else sum += budget[i];
	}
	return sum;
}

int main(void)
{
	int i, mid, start = 0, end = 0, sol;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &budget[i]);
		if (budget[i] > end) end = budget[i];
	}
	scanf("%d", &M);

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (Check(mid) <= M) {
			// ���Ѱ��� ������ �����ϸ� ���Ѱ��� ����.
			// ���Ѱ��� ��� ���.
			start = mid + 1;
			sol = mid;
		}
		else {
			// ���Ѱ��� ������ �Ұ����ϸ� ���Ѱ��� ����.
			end = mid - 1;
		}
	}
	printf("%d\n", sol);
	return 0;
}

#endif

/***********************************************************/
// ���̷���_�������
/***********************************************************/
#if 0

#if 0
// ���� ����� �̿�.

#include <stdio.h>

int N, M, cnt;
int chk[110];
int Network[110][110];

void FF(int no)
{
	int i;

	for (i = 1; i <= N; i++) {
		// no�� ��ǻ�Ϳ� ����Ǿ������鼭 �湮���� ���� ��ǻ�Ϳ� ���� ����.
		if (Network[no][i] == 1 && chk[i] == 0) {
			chk[i] = 1;
			cnt++;
			FF(i);	// i�� ��ǻ�Ϳ� ����� ��ǻ�͵��� Ž��.
		}
	}
}

int main(void)
{
	int i, com1, com2;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d ", &com1, &com2);
		Network[com1][com2] = 1;
		Network[com2][com1] = 1;
	}
	chk[1] = 1;
	FF(1);	// 1�� ��ǻ�Ϳ� ����� ��ǻ�͵��� Ž��.
	printf("%d\n", cnt);
	return 0;
}

#endif

#if 0
// ��������Ʈ�� �̿�.

#include <stdio.h>

int N, M;
int linked[110][2];
int Start[110];

void Qsort(int start, int end)
{
	int pivot, left, target, temp;

	if (start >= end) return;

	pivot = end;
	target = start;

	for (left = start; left < end; left++)
	{
		if (linked[left][0] < linked[pivot][0])
		{
			temp = linked[left][0];
			linked[left][0] = linked[target][0];
			linked[target][0] = temp;

			temp = linked[left][1];
			linked[left][1] = linked[target][1];
			linked[target][1] = temp;

			target++;
		}
	}
	temp = linked[pivot][0];
	linked[pivot][0] = linked[target][0];
	linked[target][0] = temp;

	temp = linked[pivot][1];
	linked[pivot][1] = linked[target][1];
	linked[target][1] = temp;

	Qsort(start, target - 1);
	Qsort(target + 1, end);
}

int main(void)
{
	int i, com1, com2;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d ", &com1, &com2);
		linked[com1][com2] = 1;
	}

	return 0;
}

#endif

#endif

/***********************************************************/
// Hash_Table
/***********************************************************/
#if 0

#include <stdio.h>
#define MAX      10
#define HASH_KEY 5 
#define STEP     1 

int Hash_table[MAX] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //�ʱⰪ -1��
int test[MAX] = { 1, 5, 3, 4, 9, 10, 11, 6, 2, 7 }; //�׽�Ʈ��

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}
void Print_All_Data(void)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[i] > 0) printf("[%d] data=%d\n", i, Hash_table[i]);
	}
}
int Insert_Data(int  data)
{
	int i, key;
	key = Get_Hash_Key(data);

	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[key] <= 0)
		{
			Hash_table[key] = data;
			return key;
		}
		// �ߺ� ���̵� üũ.
		else if (Hash_table[key] == data) return -1;
		// �� ���� ã�� �ݺ�.
		key = (key + STEP) % MAX;
	}
	return -1;
}

int Delete_Data(int data)
{
	int i, key;
	key = Get_Hash_Key(data);

	for (i = 0; i < MAX; i++)
	{
		if (Hash_table[key] == -1) return -1;
		else if (Hash_table[key] == data)
		{
			Hash_table[key] = 0;
			return key;
		}
		key = (key + STEP) % MAX;
	}
	return -1;
}

void main(void)
{
	int i, r;
	for (i = 0; i < MAX; i++) Insert_Data(test[i]);
	Print_All_Data();
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[3] Delete Result=%d\n", r = Delete_Data(3));
	Print_All_Data();
}

#endif

/***********************************************************/
// �ϼ� ���ξ�	
/***********************************************************/
#if 0

#include <stdio.h>
#define MAX      200000
#define STEP     1 

typedef struct {
	int x, id;
}COW;

COW cow[50001];		// �ҵ��� ��ġ�� ���̵� ������ ���� ����ü �迭.
COW buf[50001];
int new_id[MAX];	// ���ο� ID�� ���� �ؽ� ���̺�.
int id_chk[MAX];	// ���̵� üũ�� ���� �迭.
int id_cnt;			// ���̵� ���� ��.
int N;

void Msort(int start, int end)
{
	int mid, i, j, k;

	if (start >= end) return;

	mid = (start + end) / 2;
	Msort(start, mid);		// ��  �� ���� ������
	Msort(mid + 1, end);	// ������ ���� ������

	i = start;		// ��  �� ���� ���� ��ġ
	j = mid + 1;	// ������ ���� ���� ��ġ
	k = start;		// �� �� �� �� ���� ��ġ 

	while (i <= mid && j <= end) {// ���� �̳� ������ ������ ���� �ٴٸ��� ����.
		if (cow[i].x < cow[j].x) buf[k++] = cow[i++];
		else buf[k++] = cow[j++];
	}
	while (i <= mid) { // ��  ���� ���� ���
		buf[k++] = cow[i++];
	}
	while (j <= end) { // �������� ���� ���
		buf[k++] = cow[j++];
	}
	// �ӽ� ������ ���� �� �����Ϳ� ����.
	for (i = start; i <= end; i++) cow[i] = buf[i];
}

int get_new_id(int id)
{
	int i, key; key = id % MAX;
	for (i = 0; i < MAX; i++) {
		if (new_id[key] == 0) {
			id_cnt++;
			new_id[key] = id;
			return key;
		}
		// �ߺ� ���̵� üũ.
		else if (new_id[key] == id) return key;
		// �� ���� ã�� �ݺ�.
		key = (key + STEP) % MAX;
	}
	return -1;
}

int Solve(void)
{
	int start, end, type = 0, min = 0x7FFFFFFF, dist;

	for (start = 0, end = 0; start < N; start++)
	{
		if (id_chk[cow[start].id] == 0) type++;
		id_chk[cow[start].id]++;

		while (type == id_cnt)
		{
			dist = cow[start].x - cow[end].x;
			if (dist < min) min = dist;

			id_chk[cow[end].id]--;
			if (id_chk[cow[end].id] == 0) type--;
			end++;
		}
	}
	return min;
}

int main(void)
{
	int i, id;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &cow[i].x, &id);
		cow[i].id = get_new_id(id);
	}
	Msort(0, N - 1);
	printf("%d\n", Solve());
	return 0;
}

#endif

/***********************************************************/
// Heap Sort_Maximum
/***********************************************************/
#if 0

#include <stdio.h>
#define MAX_HEAP (30000)

int N;
int heap[MAX_HEAP + 1];
int lastnode = 0;

int Heap_Push(int data)
{
	int parent, child, temp;

	if (lastnode == MAX_HEAP) return -1;	// ������ ������ -1 ����
	heap[++lastnode] = data;				// �� ������ ������ ����.

	child = lastnode; parent = child / 2;	// �ڽİ� �θ� �� ����.

	while (parent > 0)
	{
		if (heap[parent] < heap[child])
		{
			temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;

			child = parent; parent = child / 2;
		}
		else break;
	}
	return 1;
}

int Heap_Pop(int *p)
{
	int parent, child, lchild, rchild, temp;

	if (lastnode == 0) return -1;	// ����� �����Ͱ� ������ -1 ����
	*p = heap[1];					// �ֻ��� ��� ������ ���� ����.
	heap[1] = heap[lastnode--];		// ������ ��带 �ֻ��� ��忡 ����. ��Ʈ �� ����.

	parent = 1; lchild = 2; rchild = 3;

	while (lchild <= lastnode)		// ���� �ڽ��� ������ ����.
	{
		// ���� �ڽ��� ���ϱ� ���� �ڽ��� ���� ��.
		if (lastnode == lchild) child = lchild;
		else if (heap[lchild] > heap[rchild]) child = lchild;
		else child = rchild;

		if (heap[parent] < heap[child])
		{
			temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;

			parent = child; lchild = 2 * parent; rchild = 2 * parent + 1;
		}
		else break;
	}
	return 1;
}

int main(void)
{
	int i, data;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &data);
		Heap_Push(data);
	}

	for (i = N; i >= 1; i--) {
		Heap_Pop(&data);
		heap[i] = data;
	}

	for (i = 1; i <= N; i++) {
		printf("%d ", heap[i]);
	}
	return 0;
}

#endif

/***********************************************************/
// �ּ� ������� ���� �ٽ� �ϱ�
/***********************************************************/
#if 0

#include <stdio.h>
#define MAX 20000

int N;
int Candy[MAX];
int lastnode;

int Heap_Push(int data)
{
	int parent, child, temp;

	if (lastnode == MAX) return -1;			// ������ ������ -1 ����
	Candy[++lastnode] = data;				// �� ������ ������ ����.

	child = lastnode; parent = child / 2;	// �ڽİ� �θ� �� ����.

	while (parent > 0)
	{
		if (Candy[parent] > Candy[child])
		{
			temp = Candy[parent];
			Candy[parent] = Candy[child];
			Candy[child] = temp;

			child = parent; parent = child / 2;
		}
		else break;
	}
	return 1;
}

int Heap_Pop(int *p)
{
	int parent, child, lchild, rchild, temp;

	if (lastnode == 0) return -1;	// ����� �����Ͱ� ������ -1 ����
	*p = Candy[1];					// �ֻ��� ��� ������ ���� ����.
	Candy[1] = Candy[lastnode--];		// ������ ��带 �ֻ��� ��忡 ����. ��Ʈ �� ����.

	parent = 1; lchild = 2; rchild = 3;

	while (lchild <= lastnode)		// ���� �ڽ��� ������ ����.
	{
		// ���� �ڽ��� ���ϱ� ���� �ڽ��� ���� ��.
		if (lastnode == lchild) child = lchild;
		else if (Candy[lchild] < Candy[rchild]) child = lchild;
		else child = rchild;

		if (Candy[parent] > Candy[child])
		{
			temp = Candy[parent];
			Candy[parent] = Candy[child];
			Candy[child] = temp;

			parent = child; lchild = 2 * parent; rchild = 2 * parent + 1;
		}
		else break;
	}
	return 1;
}

void sort(int start)
{
	int i, j, temp;
	for (i = start; i < start + 2; i++) {
		for (j = i + 1; j < N; j++) {
			if (Candy[i] < Candy[j])
			{
				temp = Candy[i];
				Candy[i] = Candy[j];
				Candy[j] = temp;
			}
		}
	}
}

int main(void)
{
	int i, data, sum = 0;
	int d1, d2;

	/*	// �ܼ������� �̿�.
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &Candy[i]);

	for (i = 0; i < N; i++) {
	sort(i);
	Candy[i + 1] += Candy[i];
	sum += Candy[i + 1];
	}
	printf("%d\n", sum); */

	// Heap Sort �̿�
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &data);
		Heap_Push(data);
	}
	for (i = 0; i < N - 1; i++)
	{
		Heap_Pop(&d1); Heap_Pop(&d2);
		sum += (d1 + d2);
		Heap_Push(d1 + d2);
	}
	printf("%d\n", sum);
	return 0;
}

#endif

/***********************************************************/
// �ڿܼ��� ���� ����
/***********************************************************/
#if 0

#if 0
// DFS �̿��ϱ�
#include <stdio.h>

typedef struct {
	int r, c, sum;
}STEP;

int N, min = 0x07fffffff;
int map[110][110];
int chk[110][110];

int dr[4] = { 0, 1, 0, -1 }; // ��, ��, ��, �� ���� (�ð� ����)
int dc[4] = { 1, 0, -1, 0 };

void DFS(int sr, int sc, int sum)
{
	int k, nr, nc;
	// ���� ����
	if (sr == N && sc == N) {
		if (sum < min) min = sum;
		return;
	}
	for (k = 0; k < 4; k++)
	{
		nr = sr + dr[k]; nc = sc + dc[k];
		if (chk[nr][nc] == 1 || nr<1 || nr>N || nc<1 || nc>N) continue;

		chk[nr][nc] = 1;
		DFS(nr, nc, sum + map[nr][nc]);
		chk[nr][nr] = 0;
	}
}

int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	chk[1][1] = 1;
	DFS(1, 1, map[1][1]);
	printf("%d\n", min);
	return 0;
}

#endif

#if 0
// BFS �̿��ϱ�
#include <stdio.h>

typedef struct {
	int r, c;
}STEP;

STEP que[110 * 110 * 10];
int rp, wp;

int N;
int map[110][110];
int rec[110][110];

int dr[4] = { 0, 1, 0, -1 }; // ��, ��, ��, �� ���� (�ð� ����)
int dc[4] = { 1, 0, -1, 0 };

void In_Que(int row, int col)
{
	que[wp].r = row;
	que[wp].c = col;
	wp++;
}

// �� �ּ��� ��츦 �湮�ϵ���! rec �迭�� ���� ���Ͽ� ���� �ذ� �� �ּ����� �Ǵ�.
void BFS(void)
{
	STEP temp;
	int k, nr, nc;

	In_Que(1, 1);
	rec[1][1] += map[1][1];

	while (rp < wp)
	{
		temp = que[rp++];

		for (k = 0; k < 4; k++)
		{
			nr = temp.r + dr[k];
			nc = temp.c + dc[k];

			if (nr<1 || nr>N || nc<1 || nc>N) continue;

			// ������ �غ��� ���� �ذ� �� �ּ��̸� ť�� �����ϰ� ���.
			if (rec[nr][nc] > rec[temp.r][temp.c] + map[nr][nc])
			{
				rec[nr][nc] = rec[temp.r][temp.c] + map[nr][nc];
				In_Que(nr, nc);
			}
		}
	}
}

int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
			rec[i][j] = 0x7fffffff;
		}
	}
	rec[1][1] = 0;
	BFS();
	printf("%d\n", rec[N][N]);
	return 0;
}

#endif

#if 0
// ����� �� ���.
#include <stdio.h>

int N;
int map[110][110];
int sum[110][110];

int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 1; i < N; i++) {	// ù �� ���
		sum[0][i] = map[0][i - 1] + map[0][i];
	}
	for (i = 1; i < N; i++) {	// ù �� ���
		sum[i][0] = map[i - 1][0] + map[i][0];
	}
	for (i = 1; i < N; i++) {	// ������ ��� ���
		for (j = 1; j < N; j++) {
			if (sum[i - 1][j] > sum[i][j - 1]) sum[i][j] = map[i][j] + sum[i][j - 1];
			else sum[i][j] = map[i][j] + sum[i - 1][j];
		}
	}
	printf("%d\n", sum[N - 1][N - 1]);
	return 0;
}

#endif

#if 0
// �ּ� Heap Tree �̿� > ��湮�� �ƴ϶� �湮 üũ�� �̿�.
// �̹� �湮�� �ڸ��� �ּҰ����� �湮�� �ڸ��̹Ƿ� �ٽ� �湮�� �ʿ䰡 ����.

#include <stdio.h>

typedef struct {
	int r, c, sum;
}QUE;

QUE heap[110 * 110];
int lastnode;

int N;
int map[110][110];
int chk[110][110];

int dr[4] = { 0, 1, 0, -1 }; // �� �� �� ��
int dc[4] = { 1, 0, -1, 0 };

void Push(int r, int c, int sum)
{

}

void Pop(QUE *data)
{

}

int BFS(void)
{
	QUE temp;
	int nr, nc, i;
	int dr[4] = { 0, 1, 0, -1 }; // �� �� �� ��
	int dc[4] = { 1, 0, -1, 0 };

	// last ��尡 ���� ���� �ݺ�
	// �湮 ���� �ڸ��� ť�� �����ϰ� �湮ǥ��
}

int main(void)
{
	int i, j, sr, sc, nr, nc, min;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	sr = sc = 1;
	for (i = 0; i < 4; i++)
	{
		min = 99;
		nr = sr + dr[i];
		nc = sc + dc[i];

		if (nr < 1 || nr > N || nc < 1 || nc > N) continue;

		if ()
	}


	return 0;
}

#endif

#endif

/***********************************************************/
// �ع��� ��ȯ ȸ��
/***********************************************************/
#if 0

#include <stdio.h>

int N, min = 0x7fffffff;
int map[15][15];
int chk[15];

void Search(int no, int before, int sum)
{
	int i;
	if (no >= N)
	{
		if (map[before][1] == 0) return; // ������ ���� ����� 0�� ���� �ּҰ� �� �������� ����.
		sum += map[before][1];
		if (min > sum) min = sum;
		return;
	}
	for (i = 2; i <= N; i++)
	{
		if (map[before][i] == 0) continue;
		if (chk[i] == 1) continue;

		chk[i] = 1;
		Search(no + 1, i, sum + map[before][i]);
		chk[i] = 0;
	}
}

int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) scanf("%d", &map[i][j]);
	}
	chk[1] = 1;
	Search(1, 1, 0);
	printf("%d\n", min);
	return 0;
}

#endif

/***********************************************************/
// ����ö-SPJ
/***********************************************************/
#if 0

#include <stdio.h>

int que[101 * 101];
int rp, wp;

int N, M;
int map[101][101];
int cost[101];
int path[101];

int BFS(void)
{
	int i, temp;

	que[wp++] = 1; // 1] �������� ť�� ����.
	cost[1] = 0;   // 1] ���.

	while (rp < wp)
	{
		temp = que[rp++];	// 2] ť���� ���� ��ġ�ϰ� �ִ� ���� �б�.

		for (i = 2; i <= N; i++)
		{
			// 3] ���� �������� ����� ���� ��뺸�� ������ ť�� ����.
			if (cost[i] > cost[temp] + map[temp][i]) {
				cost[i] = map[temp][i] + cost[temp];
				que[wp++] = i;

				// 4] ���� ���� ���� ���� ��� ���.
				path[i] = temp;
			}
		}
	}
	return cost[M];	// 5] ť�� ��� �������� ����� ����.
}

void print_path(int no)
{
	if (no == 1) {
		printf("1 ");
		return;
	}
	print_path(path[no]);
	printf("%d ", no);
}

int main(void)
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		cost[i] = 0x7fffffff;
		for (j = 1; j <= N; j++) scanf("%d", &map[i][j]);
	}
	printf("%d\n", BFS());
	print_path(M);
	printf("\n");
	return 0;
}

#endif

/***********************************************************/
// ��ǻ�ͽ�(Basic)
/***********************************************************/
#if 0

#include <stdio.h>

int main(void)
{
	return 0;
}

#endif

/***********************************************************/
// ������ �� ���ϱ�
/***********************************************************/

/***********************************************************/
// ������ �ִ밪 ���ϱ�
/***********************************************************/

/***********************************************************/
// ��ȭ ��緹�� ����
/***********************************************************/
#if 0

#include <stdio.h>

int N, M;
int tree[200000 * 3];
int pos[100001]; // CD�� ��ġ ���

void Update(int node, int start, int end, int idx, int data)
{
	int mid;
	if (start == end) {
		tree[node] = data;
		return;
	}
	mid = (start + end) / 2;
	if (idx <= mid) Update(node * 2, start, mid, idx, data);
	else Update(node * 2 + 1, mid + 1, end, idx, data);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int start, int end, int qs, int qe)
{
	int mid, left, right;
	if (qs <= start && end <= qe) return tree[node];
	if (qs > end || qe < start) return 0;
	mid = (start + end) / 2;
	left = Query(node * 2, start, mid, qs, qe);
	right = Query(node * 2 + 1, mid + 1, end, qs, qe);
	return left + right;
}

int main(void)
{
	int i, ti, T, CD;
	scanf("%d", &T);
	for (ti = 0; ti < T; ti++)
	{
		scanf("%d %d", &N, &M);
		for (i = 1; i <= 200000 * 3; i++) tree[i] = 0;
		for (i = 1; i <= 100001; i++) pos[i] = 0;

		for (i = 1; i <= N; i++) {	// �ε����� ���� CD ��ȣ.
			pos[i] = M + i;			// Ʈ���� ����Ǵ� ��ġ�� ���.
			Update(1, 1, N + M, M + i, 1); // idx ��°�� CD ������ ����.
		}
		for (i = 0; i < M; i++) {	// ��ȭ ����.
			scanf("%d", &CD);
			printf("%d ", Query(1, 1, N + M, 1, pos[CD] - 1));	// �� CD ���� �ִ� ���� ���ϱ�.
			Update(1, 1, N + M, pos[CD], 0);	// CD ����.
			Update(1, 1, N + M, M - i, 1);		// CD�� �� ���� �ø���.
			pos[CD] = M - i;
		}
		printf("\n");
	}
	return 0;
}

#endif

/***********************************************************/
// ���� ��ũ�� ����Ʈ�� �����ϱ�
/***********************************************************/
#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct st {
	int num;
	struct st *prev;
}STACK;

STACK *Sptr = (STACK *)0;
int N, cnt;

int Push_Stack(int data)
{
	STACK *stack = (STACK *)calloc(1, sizeof(STACK));
	stack->num = data;
	stack->prev = Sptr;
	Sptr = stack;
	cnt++;
	return 1;
}

int Pop_Stack(STACK *data)
{
	STACK *temp = Sptr;
	if (Sptr == NULL) return -1;
	*data = *Sptr;
	Sptr = Sptr->prev;
	free(temp);
	cnt--;
	return 1;
}

int main(void)
{
	STACK temp;
	int i, cmd, data;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &data);
			Push_Stack(data);
		}
		if (cmd == 0) {
			if (Pop_Stack(&temp) == 1) printf("%d\n", temp.num);
			else printf("E\n");
		}
		if (cmd == 2) {
			printf("%d\n", cnt);
		}
	}
	return 0;
}

#endif

/***********************************************************/
// Queue#2
/***********************************************************/
#if 0

#include <stdio.h>
#include <malloc.h>

typedef struct st
{
	int id;
	struct st * rp; // next
	struct st * wp; // prev
}QUE;

QUE HEAD = { 0, NULL, NULL };
QUE TAIL = { 0, NULL, NULL };

QUE * QUEUE(int d)
{
	QUE *newnode = (QUE *)calloc(1, sizeof(QUE));

	newnode->id = d;
	newnode->wp = TAIL.wp;
	newnode->rp = &TAIL;

	newnode->wp->rp = newnode;
	TAIL.wp = newnode;

	return newnode;
}

int DEQUEUE(int *p)
{
	QUE *temp = HEAD.rp;

	if (HEAD.rp == &TAIL) return -1;

	*p = HEAD.rp->id;
	if (temp->rp) temp->rp->wp = &HEAD; // temp->rp->wp = temp->wp;
	HEAD.rp = temp->rp;
	free(temp);
	return 0;
}

int main(void)
{
	int i;
	int d;

	struct st * r, *t;
	int p[1];
	int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0 };
	int que[] = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 0, 2, 4, 6, 2, 4, 8, 10, 6, 8, 10, 0 };
	int ans[] = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0, -1, 2, 4, 6, 0, 0, 8, 10, 0, 0, 0, -1 };

	HEAD.rp = &TAIL;
	TAIL.wp = &HEAD;

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("\nTEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = QUEUE(que[i]);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (r == NULL)
			{
				printf(">>>>Ʋ��: ���ϵȱ���ü���ּҰ�NULL ��������\n");
				return 0;
			}

			if (r->id != ans[i])
			{
				printf(">>>>Ʋ��: ���ϵȱ���ü�ּ���id ����=> %d, �������ϵȱ���ü��id ��=> %d\n", ans[i], r->id);
				return 0;
			}

			if (TAIL.wp != r)
			{
				printf(">>>>Ʋ��: TAIL��wp ��ũ����(TAIL��wp�����ϵ��ڷ��ּҰ��ƴ�)\n");
				return 0;
			}

			if (r->rp != &TAIL)
			{
				printf(">>>>Ʋ��: ���ϵ��ڷ���rp��TAIL���ּҰ��ƴ�)\n");
				return 0;
			}

			t = &HEAD;

			for (;;)
			{
				if (t->rp == &TAIL) break;
				else t = t->rp;
			}

			if ((t != r) || (t->id != r->id))
			{
				printf(">>>>Ʋ��: HEAD�����κ���ã��TAIL �ٷξտ��־���ϴ±���ü�ּҿ͸��ϵȱ���ü�ּҰ��ٸ�\n");
				return 0;
			}

			printf("OK\n");
		}

		else
		{
			d = DEQUEUE(p);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (d != ans[i])
			{
				printf(">>>>Ʋ��: �����ϰ�= %d, �������ϰ�= %d\n", ans[i], d);
				return 0;
			}

			if (d != -1)
			{
				if (*p != que[i])
				{
					printf(">>>>Ʋ��: ť����������p �ּҿ�����ִµ������ǿ���=> %d, ����p �ּҿ�����ִ°�=> %d\n", que[i], *p);
					return 0;
				}
				t = &HEAD;

				for (;;)
				{
					if (t->rp == &TAIL) break;
					else t = t->rp;
				}
				t = &TAIL;

				for (;;)
				{
					if (t->wp == &HEAD) break;
					else t = t->wp;
				}
			}
			printf("OK\n");
		}
	}
	return 1;
}

#endif

/***********************************************************/
// ��ȭ��ȣ ���
/***********************************************************/
#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct st {
	int end;
	struct st *next[10];
}NODE;

NODE Head;
int N;

int Search_node(NODE *p, char *tel)
{
	int i, no;
	for (i = 0; tel[i]; i++)
	{
		no = tel[i] - '0';
		// ���� ��ȭ��ȣ�� �����ϸ� �ϰ��� ����.
		if (p->end == 1) return 1;
		// ��ũ�� ���̸� �߰��� �������Ƿ� �ϰ��� ����.
		if (p->next[no] == NULL) return 0;
		// ����� ��ũ���� �̵�.
		p = p->next[no];
	}
	return 1; // �� ���ڿ��� ���̾ �ϰ��� ����.
}

void Insert_node(NODE *p, char *tel)
{
	int i, no;
	for (i = 0; tel[i]; i++) {
		no = tel[i] - '0';
		// �ű��̸� ��� �����Ͽ� ����
		if (p->next[no] == 0) {
			NODE *newone = calloc(1, sizeof(NODE));
			p->next[no] = newone;
		}
		// ����� ��ũ���� �̵�
		p = p->next[no];
	}
	p->end = 1;
}

void Delete_node(NODE *p)
{
	int i;
	if (p == NULL) return;
	for (i = 0; i < 10; i++) {
		if (p->next[i]) Delete_node(p->next[i]);
		free(p->next[i]);
		p->next[i] = 0;
	}
}

int main(void)
{
	int ti, T;
	scanf("%d", &T);
	for (ti = 0; ti < T; ti++)
	{
		int i, flag = 0;
		char str[11];

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%s", str);
			if (flag) continue;	// �ϰ����� ���� ����̸� �Է¸� �ް� ��� ����.

			if (i != 0) flag = Search_node(&Head, str);	// ù��° ��ȭ��ȣ �ƴ� ��� �ϰ��� üũ.
			Insert_node(&Head, str); // ��ȭ��ȣ ����.
		}
		if (flag == 1) printf("NO\n");	// flag ������ 1�̸� �ϰ����� ����.
		else printf("YES\n");
		Delete_node(&Head);	// ���� �׽�Ʈ ���̽��� ���� �ʱ�ȭ.
	}
	return 0;
}

#endif

/***********************************************************/
// ������
/***********************************************************/
#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct st {
	char ch;
	struct st *next;
	struct st *prev;
}Word;

Word *Cursor;
Word Head = { 0, NULL, NULL };
Word Tail = { 0, NULL, NULL };

char str[600001];

void Delete(void)
{
	Word *temp = Cursor->prev;

	if (Cursor->prev == &Head) return;

	Cursor->prev = temp->prev; // temp->prev->next=temp->next
	temp->prev->next = Cursor; // temp->next->prev=temp->prev;
	free(temp);
}

void Insert(char c)
{
	Word *newnode = calloc(1, sizeof(Word));
	newnode->ch = c;
	newnode->next = Cursor;
	newnode->prev = Cursor->prev;

	newnode->prev->next = newnode;
	Cursor->prev = newnode;
}

void Move(int dir)	// 1 �̸� ���������� �̵�. -1 �̸� �������� �̵�.
{
	if (dir == -1) {
		if (Cursor->prev == &Head) return;
		Cursor = Cursor->prev;
	}
	else {
		if (Cursor->next == NULL) return;
		Cursor = Cursor->next;
	}
}

void Print(void)
{
	int i;
	for (;;)
	{
		if (Head.next->next == NULL) break;
		printf("%c", Head.next->ch);
		Head.next = Head.next->next;
	}
	printf("\n");
}

int main(void)
{
	int i, ncmd;
	char cmd, ch;

	scanf("%s", &str);
	scanf("%d", &ncmd);

	Cursor = &Tail;
	Head.next = &Tail;
	Tail.prev = &Head;

	for (i = 0; str[i]; i++) {
		Insert(str[i]);
	}

	for (i = 0; i < ncmd; i++)
	{
		scanf(" %c", &cmd);
		if (cmd == 'P') // Ŀ�� ���ʿ� ���� �߰�.
		{
			scanf(" %c", &ch);
			Insert(ch);
		}
		else if (cmd == 'L')	// Ŀ�� �������� �� ĭ �̵�.
		{
			Move(-1);
		}
		else if (cmd == 'D')	// Ŀ�� ���������� �� ĭ �̵�.
		{
			Move(1);
		}
		else // Ŀ�� ������ ���ڸ� ����.
		{
			Delete();
		}
	}
	Print();
	return 0;
}

#endif

/***********************************************************/
// Segment Tree
/***********************************************************/
#if 0
/***********************************************************/
// �ڷ� Ȯ��
/***********************************************************/
#if 01
#include <stdio.h>

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*2)
#define LAST_NODE	(MAX_DATA*2-1)

int tree[MAX_TREE];
int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0�� index ���� ����

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}

void Update_New_Data(int node, int s, int e, int idx, int data);
void Update_Add(int node, int s, int e, int us, int ue, int add);
int Query(int node, int s, int e, int qs, int qe);
#endif
/***********************************************************/
// ���ο� �������� �߰� �� ������ ������Ʈ �Լ�
/***********************************************************/
#if 01
void Update_New_Data(int node, int start, int end, int idx, int data)
{
	int mid;
	if (start == end) { // �ܳ��
		tree[node] = data;
		return;
	}
	mid = (start + end) / 2;
	if (idx <= mid) Update_New_Data(node * 2, start, mid, idx, data);
	else Update_New_Data(node * 2 + 1, mid + 1, end, idx, data);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; //���� ����
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_New_Data() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
		printf("[%d] data : %d ", i, exam[i]);
		PRINT_TREE;
	}
}
#endif

/***********************************************************/
// ���� ���� ��û
/***********************************************************/
#if 01
int Query(int node, int start, int end, int qs, int qe)
{
	int mid, left, right;
	if (qs <= start && end <= qe) return tree[node]; //������ ������ ����
	if (end < qs || qe < start) return 0;			 //������ ������ ��� ��� ����
	mid = (start + end) / 2;
	left = Query(node * 2, start, mid, qs, qe);
	right = Query(node * 2 + 1, mid + 1, end, qs, qe);
	return left + right;
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Query() Test\n");

	for (i = 1; i <= NUM_DATA; i++) {
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
	}
	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif

/*************************************************************/
// Ư�� ���� ������ ���� �Լ� - ������ ����/����
/*************************************************************/
#if 01
void Update_Add(int node, int start, int end, int us, int ue, int add)
{
	int mid;
	if (ue < start || end < us) return;
	if (start == end) {
		tree[node] += add;
		return;
	}
	mid = (start + end) / 2;
	Update_Add(node * 2, start, mid, us, ue, add);
	Update_Add(node * 2 + 1, mid + 1, end, us, ue, add);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
#endif

#if 0
void main(void)
{
	int i;

	printf("Update_Add() Test\n");

	for (i = 1; i <= NUM_DATA; i++)
	{
		Update_New_Data(1, 1, NUM_DATA, i, exam[i]);
	}

	printf("[Before Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));

	Update_Add(1, 1, NUM_DATA, 2, 4, 2);

	printf("\n[After Range Update] ");
	PRINT_TREE;
	printf("Query[1~5] : result = %d\n", Query(1, 1, NUM_DATA, 1, 5));
	printf("Query[1~3] : result = %d\n", Query(1, 1, NUM_DATA, 1, 3));
	printf("Query[4~5] : result = %d\n", Query(1, 1, NUM_DATA, 4, 5));
	printf("Query[2~4] : result = %d\n", Query(1, 1, NUM_DATA, 2, 4));
	printf("Query[3~5] : result = %d\n", Query(1, 1, NUM_DATA, 3, 5));
}
#endif

#endif