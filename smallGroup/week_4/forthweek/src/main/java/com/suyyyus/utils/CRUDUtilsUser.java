package com.suyyyus.utils;

import com.suyyyus.pojo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class CRUDUtilsUser {

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
            int j = preparedStatement.executeUpdate();
            //System.out.println(i);//返回修改的条数
            System.out.println("操作成功啦");
            //释放资源
            JDBCUtils.close(connection,preparedStatement);
        }catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(connection,preparedStatement,null);
        }

    }


    /**
     * 用户登录
     * @param sql
     * @param username
     * @param password
     * @return
     * @throws Exception
     */
    public static boolean UserLogin(String sql, String username, String password) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //重要的一行
        preparedStatement.setString(1,username);
        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        //是否存在这个用户
        while(resultSet.next()){
            if(MD5Util.verifySaltPassword(password,resultSet.getString("password"))){
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }

    /**
     * 查询总信息条数
     * @param sql
     * @return
     */
    public static int allCount(String sql) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        int count = 0;

        if (resultSet.next()) {
            count = resultSet.getInt(1);
        }
        return count;
    }

    /**
     * //分页查询
     * 1.开始索引 (当前页码 - 1) * 每页显示的条数
     * 2.查询的条目数
     * @param sql
     * @return
     * @throws Exception
     */
    public static List<User> selectByPage(String sql, Object... params) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);
        //填充占位符
        for (int i = 0; i < params.length; i++) {
            preparedStatement.setObject(i + 1, params[i]);
        }

        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        List<User> list = new ArrayList<>();

        while(resultSet.next()) {
            list.add(new User(resultSet.getInt("id"),resultSet.getString("cardid"),resultSet.getString("username"),
                    resultSet.getString("password"),resultSet.getString("address"),
                    resultSet.getString("gender"),resultSet.getString("create_time")));
        }
        if(list.size() == 0) {
            System.out.println("当前没有用户");
            JDBCUtils.close(connection,preparedStatement,resultSet);
            return null;
        }else {
            JDBCUtils.close(connection,preparedStatement,resultSet);
            return list;
        }

    }

    /**
     * 通过用户名查询
     * @param sql
     * @param params
     * @return
     * @throws Exception
     */
    public static User queryByUsername(String sql, Object... params) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);

        //填充占位符
        for (int i = 0; i < params.length; i++) {
            preparedStatement.setObject(i + 1, params[i]);
        }

        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        User user = new User();
        if(resultSet.next()){
            user.setCardid(resultSet.getString("cardid"));
            user.setUsername(resultSet.getString("username"));
            user.setPassword(resultSet.getString("password"));
            user.setGender(resultSet.getString("gender"));
            user.setAddress(resultSet.getString("address"));
            user.setCreate_time((resultSet.getString("create_time")));
            return user;
        }
        else{
            return null;
        }
    }


    /**
     * 确认身份证号
     * @param sql
     * @param
     * @return
     * @throws Exception
     */
    public static User confirmByCardid(String sql, Object... params) throws Exception {
        //获取连接
        connection = JDBCUtils.getConnection();
        //预编译
        preparedStatement = connection.prepareStatement(sql);

        //填充占位符
        for (int i = 0; i < params.length; i++) {
            preparedStatement.setObject(i + 1, params[i]);
        }

        //获取resultSet
        resultSet = preparedStatement.executeQuery();

        User user = new User();
        if(resultSet.next()){
            user.setCardid(resultSet.getString("cardid"));
            user.setUsername(resultSet.getString("username"));
            user.setPassword(resultSet.getString("password"));
            user.setGender(resultSet.getString("gender"));
            user.setAddress(resultSet.getString("address"));
            user.setCreate_time((resultSet.getString("create_time")));
            return user;
        }
        else{
            return null;
        }
    }

}
