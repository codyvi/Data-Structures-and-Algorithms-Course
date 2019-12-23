import java.util.*;
import java.io.*;

public class CarFueling {
    static int computeMinRefills(int dist, int tank, int[] stops) {
        int current_stop = 0;
        int numRefills = 0;
        int[] new_stops = new int[stops.length+2];
        new_stops[0] = 0;
        new_stops[new_stops.length-1] = dist;
        for(int i=0; i<stops.length; i++){
            new_stops[i+1] = stops[i];
        }

        while(current_stop < new_stops.length-1){ 
            int previous_stop = current_stop;
            while(current_stop < new_stops.length-1 && new_stops[current_stop+1] - new_stops[previous_stop] <= tank){
                current_stop++;
            }
            if(current_stop == previous_stop){
                return -1;
            }
            if(current_stop < new_stops.length-1){
                numRefills++;
            }
        }
        return numRefills;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dist = scanner.nextInt();
        int tank = scanner.nextInt();
        int n = scanner.nextInt();
        int stops[] = new int[n];
        for (int i = 0; i < n; i++) {
            stops[i] = scanner.nextInt();
        }

        System.out.println(computeMinRefills(dist, tank, stops));
    }
}