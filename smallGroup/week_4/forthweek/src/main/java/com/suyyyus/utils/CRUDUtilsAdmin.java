package com.suyyyus.utils;

import com.suyyyus.pojo.Admin;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class CRUDUtilsAdmin {
    private static PreparedStatement preparedStatement = null;
    private static Connection connection = null;
    private static ResultSet resultSet = null;


    /**
     * 管理员登录
     * @param sql
     * @param adminname
     * @return
     * @throws Exception
     */
    public static boolean checkAdmin(String sql, String adminname, String password) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //重要的一行
        preparedStatement.setString(1,adminname);
        preparedStatement.setString(2,password);
        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        //是否存在这个用户
        if(resultSet.next()){
            return true;
        }
        else {
            return false;
        }
    }


    /**
     * 查询所有
     * @param sql
     * @return
     * @throws Exception
     */
    public static List<Admin> queryAll(String sql) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        List<Admin> list = new ArrayList<>();

        while(resultSet.next()) {
            list.add(new Admin(resultSet.getInt("id"),resultSet.getString("adminname"),
                    resultSet.getString("password")));
        }
        if(list.size() == 0) {
            System.out.println("当前没有管理员");
            JDBCUtils.close(connection,preparedStatement,resultSet);
            return null;
        }else {
            JDBCUtils.close(connection,preparedStatement,resultSet);
            return list;
        }
        //释放资源

    }
}
