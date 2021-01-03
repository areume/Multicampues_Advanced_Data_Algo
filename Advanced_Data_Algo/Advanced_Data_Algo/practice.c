#pragma warning(disable: 4996)

/***********************************************************/
// 퀵 정렬
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
// Merge 정렬
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
// 이진 탐색
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
// 숫자 카운팅
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
// 숫자 카운팅 (범위)
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
// 도약
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
			// 더 작은 값을 찾기 위해 왼쪽 탐색.
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

	// 3중 for 문 이용
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

	// 이진탐색 이용
	cnt = 0;
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {

			dist = arr[j] - arr[i];
			// start ~ end 범위 이내의 양끝 경계 위치를 이용
			start = arr[j] + dist;
			end = arr[j] + dist * 2;
			// start 이상 중에서 가장 작은 값의 위치 탐색.
			lower = Binary_Search_Lower(0, N - 1, start);
			// 못찾은 경우나 범위를 벗어나는 최소값을 찾은 경우 스킵.
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
// 예산
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
			// 상한가로 배정이 가능하면 상한가를 증가.
			// 상한가를 계속 백업.
			start = mid + 1;
			sol = mid;
		}
		else {
			// 상한가로 배정이 불가능하면 상한가를 감소.
			end = mid - 1;
		}
	}
	printf("%d\n", sol);
	return 0;
}

#endif

/***********************************************************/
// 바이러스_인접행렬
/***********************************************************/
#if 0

#if 0
// 인접 행렬을 이용.

#include <stdio.h>

int N, M, cnt;
int chk[110];
int Network[110][110];

void FF(int no)
{
	int i;

	for (i = 1; i <= N; i++) {
		// no번 컴퓨터와 연결되어있으면서 방문하지 않은 컴퓨터에 대해 감염.
		if (Network[no][i] == 1 && chk[i] == 0) {
			chk[i] = 1;
			cnt++;
			FF(i);	// i번 컴퓨터에 연결된 컴퓨터들을 탐색.
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
	FF(1);	// 1번 컴퓨터에 연결된 컴퓨터들을 탐색.
	printf("%d\n", cnt);
	return 0;
}

#endif

#if 0
// 인접리스트를 이용.

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

int Hash_table[MAX] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //초기값 -1로
int test[MAX] = { 1, 5, 3, 4, 9, 10, 11, 6, 2, 7 }; //테스트값

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
		// 중복 아이디 체크.
		else if (Hash_table[key] == data) return -1;
		// 빈 방을 찾아 반복.
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
// 암소 라인업	
/***********************************************************/
#if 0

#include <stdio.h>
#define MAX      200000
#define STEP     1 

typedef struct {
	int x, id;
}COW;

COW cow[50001];		// 소들의 위치와 아이디 정보를 담을 구조체 배열.
COW buf[50001];
int new_id[MAX];	// 새로운 ID를 위한 해시 테이블.
int id_chk[MAX];	// 아이디 체크를 위한 배열.
int id_cnt;			// 아이디 가지 수.
int N;

void Msort(int start, int end)
{
	int mid, i, j, k;

	if (start >= end) return;

	mid = (start + end) / 2;
	Msort(start, mid);		// 왼  쪽 영역 나누기
	Msort(mid + 1, end);	// 오른쪽 영역 나누기

	i = start;		// 왼  쪽 영역 시작 위치
	j = mid + 1;	// 오른쪽 영역 시작 위치
	k = start;		// 임 시 버 퍼 시작 위치 

	while (i <= mid && j <= end) {// 왼쪽 이나 오른쪽 영역이 끝에 다다르면 종료.
		if (cow[i].x < cow[j].x) buf[k++] = cow[i++];
		else buf[k++] = cow[j++];
	}
	while (i <= mid) { // 왼  쪽이 남은 경우
		buf[k++] = cow[i++];
	}
	while (j <= end) { // 오른쪽이 남은 경우
		buf[k++] = cow[j++];
	}
	// 임시 버퍼의 값을 원 데이터에 복사.
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
		// 중복 아이디 체크.
		else if (new_id[key] == id) return key;
		// 빈 방을 찾아 반복.
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

	if (lastnode == MAX_HEAP) return -1;	// 공간이 없으면 -1 리턴
	heap[++lastnode] = data;				// 힙 공간에 데이터 삽입.

	child = lastnode; parent = child / 2;	// 자식과 부모 값 설정.

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

	if (lastnode == 0) return -1;	// 저장된 데이터가 없으면 -1 리턴
	*p = heap[1];					// 최상위 노드 데이터 값을 전달.
	heap[1] = heap[lastnode--];		// 마지막 노드를 최상위 노드에 대입. 라스트 값 갱신.

	parent = 1; lchild = 2; rchild = 3;

	while (lchild <= lastnode)		// 왼쪽 자식은 언제나 존재.
	{
		// 비교할 자식을 정하기 위해 자식의 값을 비교.
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
// 최소 비용으로 포장 다시 하기
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

	if (lastnode == MAX) return -1;			// 공간이 없으면 -1 리턴
	Candy[++lastnode] = data;				// 힙 공간에 데이터 삽입.

	child = lastnode; parent = child / 2;	// 자식과 부모 값 설정.

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

	if (lastnode == 0) return -1;	// 저장된 데이터가 없으면 -1 리턴
	*p = Candy[1];					// 최상위 노드 데이터 값을 전달.
	Candy[1] = Candy[lastnode--];		// 마지막 노드를 최상위 노드에 대입. 라스트 값 갱신.

	parent = 1; lchild = 2; rchild = 3;

	while (lchild <= lastnode)		// 왼쪽 자식은 언제나 존재.
	{
		// 비교할 자식을 정하기 위해 자식의 값을 비교.
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

	/*	// 단순정렬을 이용.
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &Candy[i]);

	for (i = 0; i < N; i++) {
	sort(i);
	Candy[i + 1] += Candy[i];
	sum += Candy[i + 1];
	}
	printf("%d\n", sum); */

	// Heap Sort 이용
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
// 자외선을 피해 가기
/***********************************************************/
#if 0

#if 0
// DFS 이용하기
#include <stdio.h>

typedef struct {
	int r, c, sum;
}STEP;

int N, min = 0x07fffffff;
int map[110][110];
int chk[110][110];

int dr[4] = { 0, 1, 0, -1 }; // 서, 남, 동, 북 순서 (시계 방향)
int dc[4] = { 1, 0, -1, 0 };

void DFS(int sr, int sc, int sum)
{
	int k, nr, nc;
	// 리턴 조건
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
// BFS 이용하기
#include <stdio.h>

typedef struct {
	int r, c;
}STEP;

STEP que[110 * 110 * 10];
int rp, wp;

int N;
int map[110][110];
int rec[110][110];

int dr[4] = { 0, 1, 0, -1 }; // 서, 남, 동, 북 순서 (시계 방향)
int dc[4] = { 1, 0, -1, 0 };

void In_Que(int row, int col)
{
	que[wp].r = row;
	que[wp].c = col;
	wp++;
}

// 더 최소인 경우를 방문하도록! rec 배열의 값과 비교하여 현재 해가 더 최소인지 판단.
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

			// 이전의 해보다 현재 해가 더 최소이면 큐에 저장하고 기록.
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
// 경우의 수 방법.
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

	for (i = 1; i < N; i++) {	// 첫 행 계산
		sum[0][i] = map[0][i - 1] + map[0][i];
	}
	for (i = 1; i < N; i++) {	// 첫 열 계산
		sum[i][0] = map[i - 1][0] + map[i][0];
	}
	for (i = 1; i < N; i++) {	// 나머지 행렬 계산
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
// 최소 Heap Tree 이용 > 재방문이 아니라 방문 체크를 이용.
// 이미 방문한 자리는 최소값으로 방문한 자리이므로 다시 방문할 필요가 없다.

#include <stdio.h>

typedef struct {
	int r, c, sum;
}QUE;

QUE heap[110 * 110];
int lastnode;

int N;
int map[110][110];
int chk[110][110];

int dr[4] = { 0, 1, 0, -1 }; // 서 남 동 북
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
	int dr[4] = { 0, 1, 0, -1 }; // 서 남 동 북
	int dc[4] = { 1, 0, -1, 0 };

	// last 노드가 있을 동안 반복
	// 방문 안한 자리를 큐에 저장하고 방문표시
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
// 해밀턴 순환 회로
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
		if (map[before][1] == 0) return; // 집으로 가는 비용이 0인 경우는 최소값 비교 실행하지 않음.
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
// 지하철-SPJ
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

	que[wp++] = 1; // 1] 시작점을 큐에 저장.
	cost[1] = 0;   // 1] 기록.

	while (rp < wp)
	{
		temp = que[rp++];	// 2] 큐에서 현재 위치하고 있는 역을 읽기.

		for (i = 2; i <= N; i++)
		{
			// 3] 다음 역까지의 비용이 현재 비용보다 작으면 큐에 저장.
			if (cost[i] > cost[temp] + map[temp][i]) {
				cost[i] = map[temp][i] + cost[temp];
				que[wp++] = i;

				// 4] 현재 역과 다음 역의 경로 기록.
				path[i] = temp;
			}
		}
	}
	return cost[M];	// 5] 큐가 비면 목적역의 비용을 리턴.
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
// 컴퓨터실(Basic)
/***********************************************************/
#if 0

#include <stdio.h>

int main(void)
{
	return 0;
}

#endif

/***********************************************************/
// 구간의 합 구하기
/***********************************************************/

/***********************************************************/
// 구간의 최대값 구하기
/***********************************************************/

/***********************************************************/
// 영화 블루레이 수집
/***********************************************************/
#if 0

#include <stdio.h>

int N, M;
int tree[200000 * 3];
int pos[100001]; // CD의 위치 기록

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

		for (i = 1; i <= N; i++) {	// 인덱스는 실제 CD 번호.
			pos[i] = M + i;			// 트리에 저장되는 위치를 기록.
			Update(1, 1, N + M, M + i, 1); // idx 번째에 CD 유무로 저장.
		}
		for (i = 0; i < M; i++) {	// 영화 보기.
			scanf("%d", &CD);
			printf("%d ", Query(1, 1, N + M, 1, pos[CD] - 1));	// 본 CD 위에 있는 개수 구하기.
			Update(1, 1, N + M, pos[CD], 0);	// CD 제거.
			Update(1, 1, N + M, M - i, 1);		// CD를 맨 위로 올리기.
			pos[CD] = M - i;
		}
		printf("\n");
	}
	return 0;
}

#endif

/***********************************************************/
// 스택 링크드 리스트로 구현하기
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
				printf(">>>>틀림: 리턴된구조체의주소가NULL 포인터임\n");
				return 0;
			}

			if (r->id != ans[i])
			{
				printf(">>>>틀림: 리턴된구조체주소의id 예상값=> %d, 실제리턴된구조체의id 값=> %d\n", ans[i], r->id);
				return 0;
			}

			if (TAIL.wp != r)
			{
				printf(">>>>틀림: TAIL측wp 링크오류(TAIL의wp가리턴된자료주소가아님)\n");
				return 0;
			}

			if (r->rp != &TAIL)
			{
				printf(">>>>틀림: 리턴된자료의rp가TAIL의주소가아님)\n");
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
				printf(">>>>틀림: HEAD측으로부터찾은TAIL 바로앞에있어야하는구조체주소와리턴된구조체주소가다름\n");
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
				printf(">>>>틀림: 예상리턴값= %d, 실제리턴값= %d\n", ans[i], d);
				return 0;
			}

			if (d != -1)
			{
				if (*p != que[i])
				{
					printf(">>>>틀림: 큐에서꺼내서p 주소에들어있는데이터의예상값=> %d, 실제p 주소에들어있는값=> %d\n", que[i], *p);
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
// 전화번호 목록
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
		// 끝인 전화번호가 존재하면 일관성 없음.
		if (p->end == 1) return 1;
		// 링크가 끝이면 중간에 끝났으므로 일관성 있음.
		if (p->next[no] == NULL) return 0;
		// 연결된 링크따라 이동.
		p = p->next[no];
	}
	return 1; // 내 문자열이 끝이어도 일관성 없음.
}

void Insert_node(NODE *p, char *tel)
{
	int i, no;
	for (i = 0; tel[i]; i++) {
		no = tel[i] - '0';
		// 신규이면 노드 생성하여 연결
		if (p->next[no] == 0) {
			NODE *newone = calloc(1, sizeof(NODE));
			p->next[no] = newone;
		}
		// 연결된 링크따라 이동
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
			if (flag) continue;	// 일관성이 없는 경우이면 입력만 받고 계속 진행.

			if (i != 0) flag = Search_node(&Head, str);	// 첫번째 전화번호 아닌 경우 일관성 체크.
			Insert_node(&Head, str); // 전화번호 삽입.
		}
		if (flag == 1) printf("NO\n");	// flag 변수가 1이면 일관성이 없음.
		else printf("YES\n");
		Delete_node(&Head);	// 다음 테스트 케이스를 위해 초기화.
	}
	return 0;
}

#endif

/***********************************************************/
// 에디터
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

void Move(int dir)	// 1 이면 오른쪽으로 이동. -1 이면 왼쪽으로 이동.
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
		if (cmd == 'P') // 커서 왼쪽에 문자 추가.
		{
			scanf(" %c", &ch);
			Insert(ch);
		}
		else if (cmd == 'L')	// 커서 왼쪽으로 한 칸 이동.
		{
			Move(-1);
		}
		else if (cmd == 'D')	// 커서 오른쪽으로 한 칸 이동.
		{
			Move(1);
		}
		else // 커서 왼쪽의 문자를 삭제.
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
// 자료 확인
/***********************************************************/
#if 01
#include <stdio.h>

#define NUM_DATA	(5)
#define MAX_DATA	(NUM_DATA)
#define MAX_TREE	(MAX_DATA*2)
#define LAST_NODE	(MAX_DATA*2-1)

int tree[MAX_TREE];
int exam[NUM_DATA + 1] = { 0, 1, 2, 3, 4, 5 }; // 0번 index 공간 무시

#define PRINT_TREE {int j;printf("( ");	for(j=1;j<=LAST_NODE;j++){printf("%3d ",tree[j]);}printf(")\n");}

void Update_New_Data(int node, int s, int e, int idx, int data);
void Update_Add(int node, int s, int e, int us, int ue, int add);
int Query(int node, int s, int e, int qs, int qe);
#endif
/***********************************************************/
// 새로운 데이터의 추가 및 데이터 업데이트 함수
/***********************************************************/
#if 01
void Update_New_Data(int node, int start, int end, int idx, int data)
{
	int mid;
	if (start == end) { // 단노드
		tree[node] = data;
		return;
	}
	mid = (start + end) / 2;
	if (idx <= mid) Update_New_Data(node * 2, start, mid, idx, data);
	else Update_New_Data(node * 2 + 1, mid + 1, end, idx, data);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; //정보 갱신
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
// 구간 정보 요청
/***********************************************************/
#if 01
int Query(int node, int start, int end, int qs, int qe)
{
	int mid, left, right;
	if (qs <= start && end <= qe) return tree[node]; //구간의 정보를 리턴
	if (end < qs || qe < start) return 0;			 //구간의 범위를 벗어난 경우 리턴
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
// 특정 구간 데이터 변경 함수 - 데이터 증가/감소
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