

class QuickSortRealize{

    public static void main(String[] args) {
        int a[] = {4,3,1,2,5};
        QuickSortRealize quickSortRealize = new QuickSortRealize();
        quickSortRealize.quickSort(a, 0, a.length);
        for (int key :a) {
            System.out.println(key+" ");
        }
    }

    private int getP(int a[],int l,int r) {
        int key = a[l];
        int index = r;
        for (inr i = r;i > l;i--) {
            if (a[i] >= key) {
                swap(a, index--, r);
            }
        }

        swap(a, index, r);
        return index;
    }
    public void quickSort(int a[],int l,int r) {
        if (l >= r) return;
        int index = getP(a, l, r);
        quickSort(a, l, index-1);
        quickSort(a, index+1, r);

    }
    private void swap(int a[],int l,int r) {
        a[l] = a[l]^a[r];
        a[r] = a[l]^a[r];
        a[l] = a[r]^a[l];
    }
}