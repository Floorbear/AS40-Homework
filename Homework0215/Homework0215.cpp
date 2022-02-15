#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;


class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        // 이걸 쉘로우 카피 
        // 혹은 얕은 복사라고 한다.
        //this->ArrData_ = _Other.ArrData_;
        //this->Size_ = _Other.Size_;

        // 이걸 딥 카피
        // 혹은 깊은 복사라고 한다.
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        //기존 값을 임시 배열에 저장
        DataType* Temp = new DataType[Size_];
        for (size_t i = 0; i < Size_; i++)
        {
            Temp[i] = ArrData_[i];
        }

        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;

        //남아 있던 데이터 재할당
        for (size_t i = 0; i < Size_; i++)
        {
            ArrData_[i] = Temp[i];
        }
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    GameArray NewArray = GameArray(10);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    NewArray.ReSize(5);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }


}
