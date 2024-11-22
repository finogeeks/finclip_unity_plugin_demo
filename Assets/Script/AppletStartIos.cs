using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class AppletStart : MonoBehaviour
{
    [DllImport("__Internal")]
    private static extern void appletStart(string appId);
    public void OnButtonClick()
    {
        Debug.Log("start OnButtonClick");
        appletStart("60dacf37a2b11b0001c43a17");
        Debug.Log("done appletStart ");
    }


}
