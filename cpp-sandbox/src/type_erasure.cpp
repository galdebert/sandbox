class C {
public:
  template <typename T> C(T injected) { m_injected = new T }
  void DoIt() { m_base->DoIt(); }

private:
  struct Base {
    virtual
  };
};