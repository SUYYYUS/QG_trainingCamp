package com.suyyyus.myconnectionpool;

import java.sql.Connection;
import java.sql.DriverManager;
import java.util.LinkedList;
import java.util.List;

/**
 * 数据库连接的实现
 */
public class connectionPool {
    //保存连接对象
    public static List<Connection> list = new LinkedList<>();

    static {
        //获取连接
        try {
            for (int i = 0; i < 5; i++) {
                Connection connection;
                connection = DriverManager.getConnection("jdbc:mysql:///firstweek?useSSL=false&useServerPrepStmts=true",
                        "root","csy090944CSY");
                list.add(connection);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    //获得连接对象
public static synchronized Connection getConnection() throws Exception {
        if(list.size() == 0){
            //连接被拿完了
            connectionPool.class.wait();//等待
        }
    Connection connection = list.remove(0);
    return connection;
}

//关闭连接
    public static synchronized void close(Connection connection){
        list.add(connection);
        connectionPool.class.notifyAll();//唤醒其他连接
    }

}