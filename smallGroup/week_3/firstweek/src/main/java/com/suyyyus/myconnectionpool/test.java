package com.suyyyus.myconnectionpool;

import java.sql.Connection;

public class test {
    public static void main(String[] args) throws Exception {

        for (int i = 0; i < 5; i++) {
            Connection connection = connectionPool.getConnection();
            System.out.println(connection);
            //把连接放回池中
            connectionPool.close(connection);
        }
    }
}
