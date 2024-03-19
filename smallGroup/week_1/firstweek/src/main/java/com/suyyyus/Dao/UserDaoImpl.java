package com.suyyyus.Dao;

import com.suyyyus.pojo.User;
import com.suyyyus.utils.CRUDUtils;

import java.util.List;

/**
 * 接口实现类
 */
public class UserDaoImpl implements UserDao{
    /**
     * 添加用户
     * @param user 添加的用户
     * @return 0
     */
    @Override
    public int insertUser(User user) {
        try {
            //创建SQL语句
            String sql = "insert into tb_user (username, password, gender, addr) values (?,?,?,?)";
            CRUDUtils.ZengShanGai(sql,user.getUsername(),user.getPassword(),user.getGender(),user.getAddr());
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 删除用户信息根据ID
     * @param id//主键ID
     * @return 0
     */
    @Override
    public int deleteUser(int id) {
        try {
            String sql = "delete from tb_user where id = ?";
            CRUDUtils.ZengShanGai(sql,id);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 修改用户信息
     * 功能缺陷：不能只改一个，若想修改，每次必须全填，不变的话就填原本的值，比较麻烦
     * @param user 主键ID
     * @return
     */
    @Override
    public int updateinfo(User user) {
        try {
            String sql = "update tb_user set ，username = ?, password = ?, gender = ?, addr = ?";
            CRUDUtils.ZengShanGai(sql,user.getUsername(),user.getPassword(),user.getGender(),user.getAddr());
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 查询全部用户信息
     */
    @Override
    public void queryAll() {
        try {
            String sql = "select * from tb_user";
            CRUDUtils.queryAll(sql);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 通过id查询某个用户的全部信息
     * @param id
     */
    @Override
    public void queryById(int id) {
        try {
            String sql = "select * from tb_user where id = id";
            CRUDUtils.queryById(sql,id);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
