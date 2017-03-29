package com.example.burningbliss211.incomingcall;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;
import android.widget.Toast;


public class IncomingCall extends BroadcastReceiver
{
    Context pcontext;
    @Override
    public void onReceive(Context context, Intent intent) {
        TelephonyManager manager = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);

        pcontext = context;
        MyPhoneStateListener PhoneListener = new MyPhoneStateListener();

        manager.listen(PhoneListener, PhoneStateListener.LISTEN_CALL_STATE);

    }



    private class MyPhoneStateListener extends PhoneStateListener
    {
        public void onCallStateChanged(int state, String incomingNumber)
        {
            int duration = Toast.LENGTH_LONG;

            // state = 1 means when phone is ringing
            if (state == TelephonyManager.CALL_STATE_RINGING)
            {
                String msg = "New Phone Call Event. Incoming Number: " + incomingNumber;
                Toast toast = Toast.makeText(pcontext, msg, duration);
                toast.show();
            }

            if (state == TelephonyManager.CALL_STATE_OFFHOOK)
            {
                String msg = "New Phone Call Event. Off The Hook: ";
                Toast toast = Toast.makeText(pcontext, msg, duration);
                toast.show();
            }

            if(state == TelephonyManager.CALL_STATE_IDLE)
            {
                String msg = "New Phone Call Event. Phone Is Idle";
                Toast toast = Toast.makeText(pcontext, msg, duration);
                toast.show();
            }
        }
    }

}

