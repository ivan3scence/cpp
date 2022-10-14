=====================================================
Применение и реализация алгоритмов Гамма-коррекции
=====================================================


-- `Гамма-коррекция`_ — предыскажения яркости чёрно-белого или цветоделённых составляющих цветного изображения при его записи в телевидении и цифровой фотографии.
В качестве передаточной функции при гамма-коррекции чаще всего используется степенная в виде


Vout = A * Vin^gamma


Где A служит коэффициентом, а входные Vin и выходные Vout значения — неотрицательные вещественные числа. В общем случае, если A = 1,
то входные и выходные значения находятся в пределах от 0 до 1. При равенстве gamma единице характеристика передачи полутонов линейна и перепады освещённости объекта в светах и тенях отображаются одинаково.


.. _Гамма-коррекция: https://ru.wikipedia.org/wiki/%D0%93%D0%B0%D0%BC%D0%BC%D0%B0-%D0%BA%D0%BE%D1%80%D1%80%D0%B5%D0%BA%D1%86%D0%B8%D1%8F


.. contents:: Table of Contents


Класс DisplayCustomGamma
============================


Класс отвечает за выбор и сброс настроек гаммы.


..  code-block:: c++
    :caption: `core/displaycustomgamma.h`_

    class DisplayCustomGamma : public QWidget
    {
        Q_OBJECT
    public:
        explicit DisplayCustomGamma(const QDomNode &node, QWidget *parent = 0);
        ~DisplayCustomGamma();
        void paintEvent(QPaintEvent *event);
        static void resetGamma();

    private:
        void showEvent(QShowEvent *);
        void hideEvent(QHideEvent *);

        bool eventFilter(QObject *object, QEvent *event);
        QPointer<QuickMenu> quickMenu;
        QPointer<TextBar> textOk;
        QPointer<QTimer> updateTimer;
        int prevGamma;//!< Гамма до входа в режим настройки. Используется для востановления гаммы послле выхода
    signals:
        void exit();
    };


.. _core/displaycustomgamma.h: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=core/displaycustomgamma.h;h=4464e30362944dce9ca7d455f9fb2fed89a8af85;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l18


Конструктор класса
--------------------


Конструктор класса создает объект QuickMenu (параметры меню берутся из файла `xml/menu_display_custom_gamma.xml`_)
и выставляет для него параметры (геометрические, таймер), также изменяет параметр прозрачности дисплея и выключает ключевой цвет через объект класса QDisplay.
Вызывает метод setValueWrapper, через который создает сигнал и отправляет сообщение по DBus.

..  code-block:: c++
    :caption: `core/widget.cpp.1426`_

    QDBusMessage mess =  QDBusMessage::createSignal("/teplovisor/displaydemon","displaydemon.teplovisor.iwt","set_gamma");       // не место аргуменов подставлены значения
    ...
    if (signalArgType == 0)
        mess << value.toInt();
    ...
    if(QDBusConnection::sessionBus().send(mess) == 0)
    ...

.. _xml/menu_display_custom_gamma.xml: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=xml/menu_dusplay_custom_gamma.xml;h=8dfa75334d5b35ea56a0092152d647e2e515fdf9;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l1
.. _core/widget.cpp.1426: s

..  code-block:: c++
    :caption: `core/displaycustomgamma.cpp.14`_

    DisplayCustomGamma::DisplayCustomGamma(const QDomNode &node, QWidget *parent);

.. _core/displaycustomgamma.cpp.14: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=core/displaycustomgamma.cpp;h=88348d614e69b3a83d6752bffc4e174a62606956;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l14


Метод paintEvent
---------------------


Выводит окно с черно-белым градиентом, отображая на нем сетку со значениями настроек, которые возвращает статический метод **GenericConfig::getGenericIntValue**.


..  code-block:: c++
    :caption: `core/displaycustomgamma.cpp.64`_

    void DisplayCustomGamma::paintEvent(QPaintEvent *event);

.. _core/displaycustomgamma.cpp.64: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=core/displaycustomgamma.cpp;h=88348d614e69b3a83d6752bffc4e174a62606956;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l64


Статический метод resetGamma
-----------------------------


Статический метод сбрасывает текущие настройки гаммы дисплея до стандартных, используя функцию **GenericConfig::setGenericIntValue**.
В конце выполнения выводит сообщение на дисплей.


..  code-block:: c++
    :caption: `core/displaycustomgamma.cpp.113`_

    void DisplayCustomGamma::resetGamma();


Метод setGenericIntValue
-----------------------------


Функция определяет тип настройки: в глобальной переменной “map_target” по ключу (group / groupe+key).
В зависимости от типа добавляет настройку.


..  code-block:: c++
    :caption: `part_genericconfigs/genericconfig.cpp.242`_

    void GenericConfig::setGenericIntValue(const QString &group, const QString &key, const int &value);


.. _part_genericconfigs/genericconfig.cpp.242: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=part_genericconfigs/genericconfig.cpp;h=d90b643e833900c2bc2bec1e644cac056182f4bb;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l242


В случае с методом  resetGamma все настройки отностся к типу Global, что значит он создает 17 настроек QSettings следующего образца:


..  code-block:: c++
    :caption: `part_genericconfigs/genericconfig.cpp.248`_

    settings.beginGroup("displaygamma");
    setValue("displaygamma custom_user_X", Y);


Где, X - это число от 0 до 16.
Значения Y:

=====  =====  =====  =====
0xD0   0xE3   0xF6   0x109
0x11C  0x12F  0x142  0x155
0x17B  0x18E  0x1A1  0x1B4
0x1C7  0x1DA  0x1ED  0x200
=====  =====  =====  =====


.. _part_genericconfigs/genericconfig.cpp.248: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=part_genericconfigs/genericconfig.cpp;h=d90b643e833900c2bc2bec1e644cac056182f4bb;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l248
.. _core/displaycustomgamma.cpp.113: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=core/displaycustomgamma.cpp;h=88348d614e69b3a83d6752bffc4e174a62606956;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l113


Приватные методы класса DisplayCustomGamma
---------------------------------------------------


Расположены в файле  core/displaycustomgamma.cpp.


..  code-block:: c++
    :caption: `core/displaycustomgamma.cpp.146`_

    void DisplayCustomGamma::showEvent(QShowEvent *);
    void DisplayCustomGamma::hideEvent(QHideEvent *);
    bool DisplayCustomGamma::eventFilter(QObject *object, QEvent *event);


.. _core/displaycustomgamma.cpp.146: http://git.itrunway.local/?p=mx6teplovisorsource/menuqt.git;a=blob;f=core/displaycustomgamma.cpp;h=88348d614e69b3a83d6752bffc4e174a62606956;hb=a3740b7d654241e804e296eb12dfc6025a5c8d11#l146


ShowEvent регистрирует фильтр событий в родительском классе на объект,  hideEvent удаляет.
EventFilter - метод, через который проходят прерывания, если фильтр установлен.


Виджеты гаммы
=========================


Конструктор класса QWidget соединяет сигнал объекта ServiceMenu clickGammaCustom со слотом toMenuGammaDisplay,
который создает и выводит на дисплей объект класса Menu,
на основе файла *sensors_configs.xml*. **(файла нет)**


..  code-block:: c++
    :caption: `core/widget.cpp.212`_

    QObject::connect(serviceMenu, SIGNAL(clickGammaCustom()), this, SLOT(toMenuGammaDisplay()));


.. _core/widget.cpp.212: s


.. _setValueWrapper:


Публичный  слот класса Widget setValueWrapper
--------------------------------------------------


..  code-block:: c++
    :caption: `core/widget.cpp.650`_

    void setValueWrapper(QString name, QVariant value, bool isNeedWriteSetting=true);

    //`...`_

    else if(target == DISPLAYGAMMA_CONFIG_GROUP){
        isNeedSendSignal =true;
        objectPath = DISPLAYDEMON_OBJECT_PATH;
        interface = DISPLAYDEMON_INTERFACE_NAME;
        if(property == "reset_gamma"){
            DisplayCustomGamma::resetGamma();
            isNeedWriteSetting = false;
       }
    }
    ...
    if(isNeedSendSignal) // если требуется послать сигнал
    {
        if(namesignal.isEmpty()) // имя сигнала может быть задано отдельно. Если оно не задано, то мы его генерируем сами.
            namesignal = "set_"+property;

        QDBusMessage mess =  QDBusMessage::createSignal(objectPath,interface,namesignal);
        if (signalArgType == 0)
			mess << value.toInt();
		else if (signalArgType == 1)
			mess << value.toString();
        else if (signalArgType == 2){
            mess << value.toDouble();
        }

        if(QDBusConnection::sessionBus().send(mess) == 0){
            CO_WARN("Cannot send signal ");
        }else{
            DBG("signal sended");
        }
    }


.. _core/widget.cpp.650: s
.. _...: s


Класс Menu
==============


Объект класса Menu для главного меню приложения создается на основе файла `menu.xml`_.
В этом файле заданы настройки всех подменю, в том числе и подменю гамма-коррекции дисплея.


..  code-block:: c++
    :caption: `core/menu.cpp.2432`_

    void Menu::set();


.. _core/menu.cpp.2432: sen


Метод класса set в случае выбора пользователем определенной конфигурации гаммы вызывает метод
Widget::setValueWrapper, в качестве аргументов он передает :ref:`valuename<valuename>` и :ref:`valueid<valuename>`
из `menu.xml`_.


..  code-block:: c++
    :caption: `core/menu.cpp.2663`_

    QString valuename =  items->at(tmp)->getValuename();
    QString valueid =  items->at(tmp)->getValueid();
    if( (!valueid.isEmpty()) && (!valuename.isEmpty()))
        ((Widget*)parentwidget)->setValueWrapper(valuename, valueid);
    if(dynamic_cast<RadioButton*>(items->at(tmp)))
        emit itemValueChanged();


.. _core/menu.cpp.2663: s


.. _valuename:


..  code-block:: xml
    :caption: `xml/menu.xml.5805`_

    <menu name="displaymodegamma">
        <item type="radiobutton">
            <name>custom_1</name>
            <checked>yes</checked>
            <tickicon>:/res/res/icons/tick.png</tickicon>
            <valuename>display_gamma</valuename>
            <valueid>0</valueid>
        </item>


.. _xml/menu.xml.5805: send
.. _menu.xml: s


Получается аргументами функции setValueWrapper(valuename, valueid) будут

valuename:
    
    "display_gamma"

valueid:

    "0" - "7"

Результатом выполнения :ref:`функции<setValueWrapper>` будет создание сигнала и отправка сообщения (0 - 7)
по DBus.

