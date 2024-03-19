package com.suyyyus.utils;

import com.suyyyus.pojo.User;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CRUDUtils {
    private static PreparedStatement preparedStatement = null;
    private static Connection connection = null;
    private static ResultSet resultSet = null;

    //1.增删改操作
    public static void ZengShanGai(String sql, Object... params) {
        try {
            //获取连接
            connection = JDBCUtils.getConnection();
            //预编译
            preparedStatement = connection.prepareStatement(sql);
            //填充占位符
            for (int i = 0; i < params.length; i++) {
                preparedStatement.setObject(i + 1, params[i]);
            }
            //执行语句
            int i = preparedStatement.executeUpdate();
            System.out.println(i);//返回修改的条数
            System.out.println("操作成功啦");
            //释放资源
            JDBCUtils.close(connection,preparedStatement);
        }catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(connection,preparedStatement,null);
        }

    }

    //查询全部信息
    public static void queryAll(String sql) throws Exception {
            //获取连接
            connection = JDBCUtils.getConnection();
            //预编译
            preparedStatement = connection.prepareStatement(sql);
            //获取resultSet
            resultSet = preparedStatement.executeQuery();

            List<User> list = new ArrayList<>();

            while(resultSet.next()) {
                list.add(new User(resultSet.getInt("id"),resultSet.getString("username"),
                        resultSet.getString("password"),resultSet.getString("addr"),
                        resultSet.getString("gender")));
            }
        if(list.size() == 0) {
            System.out.println("当前没有用户");
        }else {
            for (User user : list) {
                System.out.println(user);
            }
        }
        //释放资源
        JDBCUtils.close(connection,preparedStatement,resultSet);

    }

    //查询某个用户信息
    public static void queryById(String sql, int id) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        List<User> list = new ArrayList<User>();

        while(resultSet.next()) {
            if(resultSet.getInt("id") == id){
                list.add(new User(resultSet.getInt("id"),resultSet.getString("username"),
                        resultSet.getString("password"),resultSet.getString("addr"),
                        resultSet.getString("gender")));
            }
        }
if(list.size() == 0){
    System.out.println("查询失败");
}else {
    for (User user : list) {
        System.out.println(user);
    }
}

        JDBCUtils.close(connection,preparedStatement,resultSet);

    }

}


