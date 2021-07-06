# 452. Minimum Number of Arrows to Burst Balloons

這題要算有多少區塊是不重疊的

如果下一顆氣球的 start < 前一次重疊的 end 代表有重疊，不做事

如果這顆氣球 start > 前一次重疊的 end，區塊+1，並更新重疊的 end為這顆氣球的end

+ 示意

100000000001                                                        初始值
                1000000000001                                      不做事

​                                                    1000000000001  更新重疊 end