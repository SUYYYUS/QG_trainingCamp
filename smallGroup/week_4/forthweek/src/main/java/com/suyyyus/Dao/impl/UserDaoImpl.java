package com.suyyyus.Dao.impl;

import com.suyyyus.Dao.UserDao;
import com.suyyyus.pojo.User;
import com.suyyyus.utils.CRUDUtilsUser;
import com.suyyyus.utils.CardidUtil;
import com.suyyyus.utils.MD5Util;
import com.suyyyus.utils.TimeUtil;

import java.sql.Time;
import java.time.LocalDateTime;
import java.util.List;

import static com.suyyyus.utils.CRUDUtilsUser.*;

/**
 * 实现UserDao接口的方法
 */
public class UserDaoImpl implements UserDao {
    /**
     * 添加用户
     * @param user
     */
    @Override
    public void insertUser(User user) {
        try {
            CardidUtil cardidUtil = new CardidUtil();
            TimeUtil timeUtil = new TimeUtil();
            //创建SQL语句
            String saltPassword = (MD5Util.generateSaltPassword(user.getPassword()));
            String sql = "insert into tb_user (cardid, username, password, gender, address, create_time) values (?,?,?,?,?,?)";
            ZengShanGai(sql,cardidUtil.idNumber(), user.getUsername(),saltPassword,user.getGender(),user.getAddress(), timeUtil.createTime());
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public void deleteUser(int id) {

    }

    @Override
    public void deleteUsers(int[] id) {

    }

    @Override
    public int updateinfo(User user) {
        return 0;
    }

    @Override
    public List<User> queryAll() {
        return null;
    }

    @Override
    public List<User> queryById(int id) throws Exception {
        return null;
    }

    @Override
    public List<User> selectByPage(int begin, int size) {
        String sql = "select * from tb_user limit  ? , ?";
        List<User> list = null;
        try {
            list = CRUDUtilsUser.selectByPage(sql,begin,size);
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return list;
    }

    @Override
    public int selectAllCount() throws Exception {
        String sql = "select count(*) from tb_user ";
        int count = allCount(sql);
        return count;
    }

    @Override
    public List<User> queryByAddress(String address) throws Exception {
        return null;
    }

    /**
     * 用户登录
     * @param username
     * @param password
     * @return
     * @throws Exception
     */
    @Override
    public boolean userLogin(String username, String password) throws Exception {
        String sql = "select * from tb_user where username = ? ";
        boolean b = UserLogin(sql, username, password);
        return b;
    }

    /**
     * 判断是否已经存在这个用户名
     * @param username
     * @return
     * @throws Exception
     */
    @Override
    public boolean checkUsername(String username) throws Exception {
        String sql = "select * from tb_user where username = ? ";
        User user =CRUDUtilsUser.queryByUsername(sql, username);
        if(user == null){
            return false;
        }
        else {
            return true;
        }
    }

    /**
     * 通过用户名查询信息
     * @param username
     * @return
     */
    @Override
    public User queryByUsername(String username) throws Exception {
        String sql = "select * from tb_user where username = ?";
        User user = CRUDUtilsUser.queryByUsername(sql, username);
        return user;
    }


    @Override
    public User confirmByCardid(String cardid) throws Exception {

        String sql = "select * from tb_user where cardid = ?";
        User b = CRUDUtilsUser.confirmByCardid(sql, cardid);

        return b;

    }

    /**
     * 重置密码
     * @return
     */
    @Override
    public void resetPassword(String cardid) {

        String resetpassword = MD5Util.generateSaltPassword("123456");
        String sql = "update tb_user set password = ? where cardid = ?";
        CRUDUtilsUser.ZengShanGai(sql,resetpassword,cardid);

    }
}
