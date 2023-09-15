#pragma once

class IInput{
public:
    virtual void Setup();
    virtual void Loop();
    virtual void Print();
};