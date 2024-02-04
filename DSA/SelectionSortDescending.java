public abstract class SelectionSortDescending {
    public static void SelectionSort() {
        for (int turn = 0; turn < arr.length; turn++) {
            int minPos = turn;
            for (int j = turn + 1; j < arr.length; j++) {
                if (arr[minpos] < arr[j]) {
                    minpos = j;
                }
            }
            int temp = arr[turn];
            arr[turn] = arr[minpos];
            arr[minpos] = temp;
        }
    }
}
