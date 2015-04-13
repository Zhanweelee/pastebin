订单管理系统接口文档
===================


如有任何问题请联系 **QQ 1206912369**[^stackedit]. 最后更新日期：2015.04.13

----------
> 关于接口返回值（JSON格式），形式如
> `{status: true, msg: "操作成功"}`或
> `{status: false, msg: "操作失败, 无法……"}`
>具体提示信息在 **msg** 会给出，根据接口不同返回相应的提示内容。

>关于时间参数
>用于存储时间的变量为整数，数值为当前Unix时间戳
>如`1428938304` 对应的时间为`2015/4/13 23:18:24`
>参考资料[http://tool.chinaz.com/Tools/unixtime.aspx]

User 用户
--------

|   接口   | 路径 | 请求参数 | 备注 |
 --------- | --- | --- | ---
| 认证 | /user/authorize | `{uname: "admin", passwd: "1234"}`| |
| 退出 | /user/logout | `{}`| |
| 查看 | /user/fetch | `{uname: "admin"}`| 如果无uname参数，则返回用户列表；否则返回指定用户信息 |
| 添加 | /user/add | `{uname: "admin", passwd: "***", display: "Zhangsan", sex: 0, age: 18, address: "Beijing XXX area", level: 0}`| 如果当前用户权限为0，则返回错误；参数中uname和passwd不为空，其他可选； |
| 删除 | /user/delete | `{uname: "abc"}`| 删除指定用户 |
| 更新 | /user/update | `{uname: "abc", passwd: "aaa"}`| 更新当前用户信息 |


----------


Supplier 供应商
--------

|   接口   | 路径 | 请求参数 | 备注 |
 --------- | --- | --- | ---
| 查看 | /supplier/fetch | `{id: 1}`| 如果无id参数，则返回供应商列表；否则返回指定供应商信息 |
| 添加 | /supplier/add | `{name: "张三", contact: "13800000000", address: "Beijing XXX area", relationship: 1, mark: "鸭掌"}`| 需要权限为1的管理员才可操作；参数中name不可为空，其他可选 |
| 删除 | /supplier/delete | `{id: 1}`| 需要权限为1的管理员才可操作 |
| 更新 | /supplier/update | `{id: 1, name: "李四", contact: "13800000001", address: "Guangdong XXX area", relationship: 5, mark: "鸡爪"}`| 需要权限为1的管理员才可操作 |


----------


Client 客户
--------

|   接口   | 路径 | 请求参数 | 备注 |
 --------- | --- | --- | ---
| 查看 | /client/fetch | `{id: 1}`| 如果无id参数，则返回客户列表；否则返回指定客户信息 |
| 添加 | /client/add | `{name: "张三", contact: "13800000000", address: "Beijing XXX area", relationship: 1, mark: "新客户"}`| 需要权限为1的管理员才可操作；参数中name不可为空，其他可选 |
| 删除 | /client/delete | `{id: 1}`| 需要权限为1的管理员才可操作 |
| 更新 | /client/update | `{id: 1, name: "李四", contact: "13800000001", address: "Guangdong XXX area", relationship: 5, mark: "老客户"}`| 需要权限为1的管理员才可操作 |


----------


Stock 库存
--------

|   接口   | 路径 | 请求参数 | 备注 |
 --------- | --- | --- | ---
| 查看 | /Stock/fetch | `{sid: 1}`| 如果无sid参数，则返回库存列表；否则返回指定品类信息 |
| 添加 | /Stock/add | `{sid: XYX020, sname: "鲜鱿鱼", unit: "20", quantity: "200"}`| 参数中unit为单件质量，quantity为库存数量；参数中sid必选不可为空，其他可选 |
| 删除 | /Stock/delete | `{sid: XYX020}`|  |
| 更新 | /Stock/update | `{sid: XYX020, sname: "腌制鱿鱼", unit: "30", quantity: "500"}`| 手动修改库存信息，sid为必选，其他参数可选 |


----------



Storage 订单
--------

>入库单接口和出库单接口类似

|   接口   | 路径 | 请求参数 | 备注 |
 --------- | --- | --- | ---
| 获取 | /Storage/fetchIn | `{id: 20150411000001}`| 如果无单号id参数，则返回列表；否则返回指定信息 |
| 添加 | /Storage/addIn | `{sid: "XYX020", quantity: "100", expectation: "1428938304", supplier: 2 }`| 其中参数sid为品类ID号，其他可选，默认为0或空 |
| 入库 | /Storage/confirmIn | `{inid: 20150411000001}`|
| 作废 | /Storage/discardIn | `{inid: 20150411000001}`|
| 重置 | /Storage/resetIn | `{inid: 20150411000001}`|



|   接口   | 路径 | 请求参数 | 备注 |
 ------ | --- | --- | ---
| 获取 | /Storage/fetchOut | `{id: 20150412000001}`| 如果无单号id参数，则返回列表；否则返回指定信息 |
| 添加 | /Storage/addOut | `{sid: "XYX020", quantity: "100", expectation: "1428938304", supplier: 2 }`| 其中参数sid为品类ID号，其他可选，默认为0或空 |
| 出库 | /Storage/confirmOut | `{inid: 20150412000001}`|
| 作废 | /Storage/discardOut | `{inid: 20150411000001}`|
| 重置待出库 | /Storage/resetOut | `{inid: 20150411000001}`|


----------