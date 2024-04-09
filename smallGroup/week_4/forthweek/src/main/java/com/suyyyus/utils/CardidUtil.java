package com.suyyyus.utils;

import java.util.Random;

public class CardidUtil {

    public String idNumber(){
        Random r = new Random();
        String idnumber = "";
        for (int i = 0; i < 8; i++) {
            int n = r.nextInt(9);
            idnumber += n;
        }

        return idnumber;
    }
}
