package com.spmno.patest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        //TextView tv = (TextView) findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
        Button openPAButton = (Button)findViewById(R.id.button_openpa);
        openPAButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openPA();
            }
        });

        Button closePAButton = (Button)findViewById(R.id.button_closepa);
        closePAButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                closePA();
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void openPA();
    public native void closePA();
}
