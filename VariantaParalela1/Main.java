package com.ace.ucv.ro;

import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;

public class Main {
    public static void main(String[] args) throws IOException, URISyntaxException {
        ForkJoinPool pool = new ForkJoinPool();
        MergeSortUtil mergeSortUtil = new MergeSortUtil();
        int[] array = mergeSortUtil.readVectorFromFile("data_set_12.txt");

        MergeSortTask task = new MergeSortTask(array, 0, array.length - 1);
        long startTime = System.nanoTime();
        pool.invoke(task);
        long elapsedTime = System.nanoTime() - startTime;
        System.out.println("A durat " + elapsedTime/1000000 + " milisecunde.");
        System.out.println(Arrays.toString(array));
    }
}
