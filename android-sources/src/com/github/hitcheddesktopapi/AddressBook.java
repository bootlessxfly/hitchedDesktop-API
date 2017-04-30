package com.github.hitcheddesktopapi;

import org.qtproject.qt5.android.QtNative;
import org.qtproject.qt5.android.bindings.QtActivity;

import android.content.ContentResolver;
import android.database.Cursor;
import android.provider.ContactsContract;
import android.app.Activity;

import java.util.ArrayList;

public class AddressBook extends QtActivity {
    public static ArrayList<String> getAddressBook() {
        Activity activity = QtNative.activity();

        ContentResolver cr = activity.getApplicationContext().getContentResolver();
        Cursor cur = cr.query(ContactsContract.Contacts.CONTENT_URI,
                null, null, null, null);
        ArrayList<String> list = new ArrayList<String>();

        if (cur.getCount() > 0) {
            while (cur.moveToNext()) {
                String id = cur.getString(
                        cur.getColumnIndex(ContactsContract.Contacts._ID));
                String name = cur.getString(cur.getColumnIndex(
                        ContactsContract.Contacts.DISPLAY_NAME));
                list.add(name);

//                if (cur.getInt(cur.getColumnIndex(
//                            ContactsContract.Contacts.HAS_PHONE_NUMBER)) > 0) {
//                    Cursor pCur = cr.query(
//                            ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
//                            null,
//                            ContactsContract.CommonDataKinds.Phone.CONTACT_ID +" = ?",
//                            new String[]{id}, null);
//                    while (pCur.moveToNext()) {
//                        String phoneNo = pCur.getString(pCur.getColumnIndex(
//                                ContactsContract.CommonDataKinds.Phone.NUMBER));
//                    }
//                    pCur.close();
//                }
            }
        }
        return list;
    }
}
