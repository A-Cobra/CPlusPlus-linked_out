#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Profesional {

};



class Empresa {
    string nombre;
    string descripcion;

public:

    Empresa() {}
    
    string getNombre() { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }
    string getDescripcion() { return descripcion; }
    void setDescripcion(string descripcion) { this->descripcion = descripcion; }

};



class Oficio {
    string tipo;
    vector<Profesional*> profesionales;
    vector<Empresa*> empresas;
public:

    
    Oficio(string tipo) : tipo(tipo) {

    }
    void insertarProfesional(Profesional* profesional) {
        profesionales.push_back(profesional);
    }
    void eliminarProfesional(size_t posicion) {
        profesionales.erase(profesionales.begin() + posicion);
    }
    void insertarEmpresas(Empresa* empresa) {
        empresas.push_back(empresa);
    }
    void eliminarEmpresa(size_t posicion) {
        empresas.erase(empresas.begin() + posicion);
    }
    size_t cantidadProfesionales() {
        return profesionales.size();
    }
    size_t cantidadEmpresas() {
        return empresas.size();
    }

    
    void mostrarProfesionales(function<void(Profesional*)> criterio) {
        for (size_t i = 0; i < profesionales.size(); ++i)
            criterio(profesionales.at(i));
    }
    void mostrarEmpresas(function<void(Empresa*)> criterio) {
        for (size_t i = 0; i < empresas.size(); ++i)
            criterio(empresas.at(i));
    }
    
    
    void setTipo(string tipo) { this->tipo = tipo; }
    string getTipo() { return tipo; }
    void setProfesionales(vector<Profesional*> profesionales) {
        this->profesionales = profesionales;
    }
    vector<Profesional*> getProfesionales() {
        return profesionales;
    }
    void setEmpresas(vector<Empresa*> empresas) {
        this->empresas = empresas;
    }
    vector<Empresa*> getEmpresas() {
        return empresas;
    }
    Profesional* getProfesional(size_t posicion) {
        return profesionales[posicion];
    }
    Empresa* getEmpresa(size_t posicion) {
        return empresas[posicion];
    }


    
};


