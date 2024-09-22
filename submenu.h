#pragma once
#include "TrabajosManager.h"
#include "ClientesManager.h"
#include "StockManager.h"
#include "GastoIngresoManager.h"

class submenu{
    public:
        void subprograma1();
        void subprograma2();
        void subprograma3();
        void subprograma4();
    private:
        int _opcion;
        TrabajosManager _ObjTrabajosManager;
        ClientesManager _ObjClientesManager;
        StockManager _ObjStockManager;
        GastoIngresoManager _ObjGastoIngresoManager;
};
