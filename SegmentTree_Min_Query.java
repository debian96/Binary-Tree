import java.util.Scanner;

public class SegmentTree_Min_Query {
	
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n,arr[],st[],qlow,qhigh,min;
		System.out.println("Enter array size");
		n = sc.nextInt();
		
		arr = new int[n];
		
		System.out.println("Enter array elements");
		
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		//Segment tree size
		int x=(int)Math.ceil(Math.log(n)/Math.log(2));
        x=2*(int)Math.pow(2, x)-1;
        
        st = new int[x];
        
        //Root of ST 
        int pos = 0;
        
        construct_ST(arr,st,0,n-1,pos);
        
        System.out.println("Enter starting index of query range");
        qlow = sc.nextInt();
        
        System.out.println("Enter ending index of query range");
        qhigh = sc.nextInt();
        
         min = rangeMinQuery(st,qlow,qhigh,0,n-1,0);
         System.out.println("Min between  "+qlow+" to "+qhigh+" index is "+min);
	}
	
	private static int rangeMinQuery(int[] st, int qlow, int qhigh, int low, int high, int pos) {
		//Total overlap
		
		if (qlow<=low && qhigh>=high) {
			return st[pos];
		}
		if(qlow>high || qhigh<low) {
			return Integer.MAX_VALUE;
		}
		int mid = (high+low)/2;
		
		return min(
				rangeMinQuery(st, qlow, qhigh, low, mid, 2*pos+1),
				rangeMinQuery(st, qlow, qhigh, mid+1, mid, 2*pos+2)
				);
	}

	private static void construct_ST(int[] arr, int[] st, int low, int high, int pos) {
		
		if (low==high) {
			st[pos] = arr[low];
			return;
		}
		int mid  =(low+high)/2;
		
		construct_ST(arr, st, low, mid, 2*pos+1);
		construct_ST(arr, st, mid+1, high, 2*pos+2);
		
		st[pos] = min(st[2*pos+1],st[2*pos+2]);
	}
	
	private static int min(int i, int j) {
		return (i<j)?i:j;
		
	}
}
