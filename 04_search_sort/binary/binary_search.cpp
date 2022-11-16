#include <cassert>

int binary_search(int arr[], int from, int to, int findValue);

int main()
{
  int test_arr[] = {-996, -960, -944, -887, -865, -860, -846, -831, -790, -785, -700, -691, -662, -662, -647,
                    -640, -587, -532, -524, -519, -501, -497, -475, -471, -461, -457, -452, -442, -441, -416,
                    -412, -411, -390, -389, -358, -341, -306, -257, -253, -252, -248, -208, -143, -134, -82,
                    -79, -11, 21, 26, 48, 68, 69, 72, 93, 95, 99, 115, 120, 156, 164, 181, 200, 231, 252, 288,
                    304, 336, 343, 364, 402, 419, 486, 546, 584, 595, 596, 606, 627, 636, 666, 666, 683, 701,
                    740, 766, 780, 782, 794, 802, 829, 832, 837, 858, 875, 881, 882, 883, 883, 947, 959};

  int n = sizeof(test_arr) / sizeof(test_arr[0]);

  assert(binary_search(test_arr, 0, n - 1, -960) == 1);
  assert(binary_search(test_arr, 2, n - 1, -960) == -1);

  return 0;
}

/* Нерекурсивный бинарный поиск в упорядоченном массиве
    arr - массив для поиска
    findValue - элемент, который ищем
    from - с какого индакса массива ищем
    to - по какой индакс массива ищем
*/
int binary_search(int arr[], int from, int to, int findValue)
{
  while (to - from > 1) {
    int mid = (to + from) / 2;

    if (arr[mid] == findValue)
      return mid;

    if (arr[mid] < findValue)
      from = mid + 1;
    else
      to = mid;
  }

  return -1;
}