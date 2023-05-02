package com.ace.ucv.ro;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.file.Path;
import java.nio.file.Paths;

public class MergeSortUtil {
    public int[] readVectorFromFile(String fileName) throws IOException, URISyntaxException {
        Path path = Paths.get(getClass().getClassLoader()
                .getResource(fileName).toURI());

        BufferedReader reader = new BufferedReader(new FileReader(path.toFile()));
        String line = reader.readLine();
        String[] strArray = line.split("\\s+");
        int[] intArray = new int[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
            intArray[i] = Integer.parseInt(strArray[i]);
        }
        reader.close();
        return intArray;
    }
}
