#pragma once

//! Interface for list.
/*! Virtual list. */

class List
{
public:


    //! Add integer to list.
    /*!
     \param val is an integer argument.
    */
    virtual void add(int val) = 0;


    //! Remove integer from list.
    /*!
     \param val is an integer argument.
    */
    virtual void remove(int val) = 0;


    //! Checker.
    /*!
      Check if an element is in list.

     \param val is an integer argument
    */
    virtual bool isIn(int val) = 0;


    //! Return length of list.
    virtual int length() = 0;
};
