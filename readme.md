Тестовое задание №1.

Создать играбельный прототип уровня многопользовательской соревновательной игры.

Референс: Красный свет - зеленый свет.

https://youtu.be/gDuQKKnX4_s?t=506
https://youtu.be/Y1YRecb_axA?t=327

Локация.

Длинная площадь ограниченная со всех сторон стеной. В одном конце зона старта - небольшой участок на котором спавнятся игроки. На другом конце зона финиша - небольшой участок, попадая в который игрок считается победившим. Между зоной старта и зоной финиша расположено игровое поле. На границе зоны финиша и игрового поля стоит кукла, форвард вектор которой изначально направлен в направлении зоны финиша, то есть она стоит спиной к зоне старта. На противоположной от старта стене висит большой таймер, показывающий оставшееся время и несколько лампочек меняющих цвет с зеленого на красный и обратно, в зависимости от условий. В зоне финиша игроки могут свободно перемещаться до окончания раунда.

Игровой процесс.

После начала раунда кукла через рандомные интервалы времени (3-6 секунд) издает сигнал и начинает с рандомной скоростью (60-180 градусов/секунду) поворачиваться на 180 градусов, при этом лампочки загораются красным. Когда кукла полностью повернулась на 180 градусов, игроки, которые находились в движении (перемещение или вращение) издают звук и деспавнятся. Далее, через  рандомные 3-5 секунд кукла издает звук и начинает отворачиваться от игроков, а лампочки загораются зеленым. Задача игроков после старта раунда бежать по направлению к финишу, замирая, когда загорается красный свет и продолжая движение, когда загорается зеленый. Хитрость в том, что двигаться можно и после красного света, но до тех пор, пока кукла не повернулась на 180 градусов. Определяя текущую скорость поворота куклы, можно пройти чуть дальше остальных игроков.

Требования:

Мультиплеер от третьего лица. Можно локальный.
Таймер старта (№-секунд), активирующийся после присоединения к сессии №-числа игроков. Таймер самой сессии (№-минут), начинающий отсчет, после старта раунда.
Деспаун выбывших игроков и их перевод в режим обсервера (наблюдателя) с возможностью переключаться между оставшимися игроками в режиме от третьего лица и вращать камеру.
Завершение сессии, если все игроки дошли до финиша или если закончилось время, с деспауном игроков, не успевших дойти до финиша.
Показать итог сессии виджетом со списком игроков в виде трех столбцов - номер позиции игрока в порядке достижения финиша / имя игрока / сколько секунд продержался, если игрок выбыл, не дойдя до финиша.

