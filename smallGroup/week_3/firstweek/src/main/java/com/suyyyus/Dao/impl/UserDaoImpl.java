package com.suyyyus.Dao.impl;

import com.suyyyus.Dao.UserDao;
import com.suyyyus.pojo.User;
import com.suyyyus.utils.CRUDUtils;

import java.util.List;

/**
 * 接口实现类
 */
public class UserDaoImpl implements UserDao {

    /**
     * 添加用户
     * @param user 添加的用户
     * @return 0
     */
    @Override
    public void insertUser(User user) {
        try {
            //创建SQL语句
            String sql = "insert into tb_user (username, password, gender, addr) values (?,?,?,?)";
            CRUDUtils.ZengShanGai(sql,user.getUsername(),user.getPassword(),user.getGender(),user.getAddr());
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    /**
     * 删除用户信息根据ID
     * @param id//主键ID
     * @return 0
     */
    @Override
    public void deleteUser(int id) {
        try {
            String sql = "delete from tb_user where id = ?";
            CRUDUtils.ZengShanGai(sql,id);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    /**
     * 批量删除信息
     * @param id//主键Id的一个数组，批量数据
     */
    @Override
    public void deleteUsers(int[] id) {
        for (int i : id) {
            try {
                String sql = "delete from tb_user where id = ?";
                CRUDUtils.ZengShanGai(sql,i);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
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
            String sql = "update tb_user set username = ?, password = ?, gender = ?, addr = ? where id = ?";
            CRUDUtils.ZengShanGai(sql,user.getUsername(),user.getPassword(),user.getGender(),user.getAddr(),user.getId());
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 查询全部用户信息
     */
    @Override
    public List<User> queryAll()  {

        String sql = "select * from tb_user";
        List<User> list = null;
        try {
            list = CRUDUtils.queryAll(sql);
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return list;
    }



    /**
     * 通过id查询某个用户的全部信息
     * @param id
     */
    @Override
    public List<User> queryById(int id) throws Exception {

            String sql = "select * from tb_user where id = id";
            List<User> list = CRUDUtils.queryById(sql, id);
            return list;
        }

    /**
     * 分页查询
     * @param begin 开始的id
     * @param size 页面条目数
     * @return
     */
    @Override
    public List<User> selectByPage(int begin, int size){
        String sql = "select * from tb_user limit  ? , ?";
        List<User> list = null;
        try {
            list = CRUDUtils.selectByPage(sql,begin,size);
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return list;
    }


    /**
     * 查询总条数
     * @return
     * @throws Exception
     */
    @Override
    public int selectAllCount() throws Exception {
        String sql = "select count(*) from tb_user ";
        int count = CRUDUtils.allCount(sql);
        return count;
    }
}
