package com.suyyyus.Druid;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.sql.Connection;
import java.util.Properties;

/**
 * 实现对Druid数据库连接池的连接
 */
public class druid {
    public static void main(String[] args) throws Exception {
        //获取配置文件
        Properties properties = new Properties();
        //加载配置文件
        properties.load(new FileInputStream("C:\\Users\\28937\\Desktop\\qg_\\QG_trainingCamp\\smallGroup\\week_1\\firstweek\\src\\main\\java\\druid.properties"));
        //获取数据池
        DataSource dataSource = DruidDataSourceFactory.createDataSource(properties);
        //获取连接
        Connection connection = dataSource.getConnection();
        //返回连接地址，判断是否连接成功
        System.out.println(connection);
        System.out.println("连接成功");
        //释放资源
        connection.close();
    }

}
